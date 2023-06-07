#include "functions.h"

int count_svaps = 0;

QByteArray parse(QByteArray message)
{
    QList parts = message.split('&');

    if (parts.size() != 3)
        return "Неверное количество аргументов\r\n\n";

    if (parts[0] == "sort")
    {
        bool is_success = false;
        int step = parts[1].toInt(&is_success, 10);

        if (!is_success || step <= 0)
            return "Неверное значение шага\r\n\n";

        QList array_parts = parts[2].split(' ');

        if (array_parts.isEmpty())
            return "Введие корректный массив\r\n\n";

        QList<int> array = {};

        for (const auto &index : array_parts){
            array.append(index.toInt());
        }

        heapSort(array, step);

        QString result = "";

        for (int index = 0; index < array.size(); index++) {
            result = result + QByteArray::number(array[index]) + " ";
        }

        return QByteArray(result.toUtf8() + "\r\n\n");
    }

    return "Я не знаю команду "  + parts[0] + "\r\n\n";
}

void heapify(QVector<int>& array, int array_size, int index) {
    int largest = index; // Инициализируем наибольший элемент как корень
    int left_index = 2 * index + 1; // Левый потомок
    int right_index = 2 * index + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left_index < array_size && array[left_index] > array[largest])
        largest = left_index;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right_index < array_size && array[right_index] > array[largest])
        largest = right_index;

    // Если наибольший элемент не является корнем
    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        // Применяем просеивание вниз рекурсивно для затронутой под-пирамиды
        heapify(array, array_size, largest);
    }
}

// Просеивание элемента вниз для создания пирамиды
bool heapify(QVector<int>& array, int array_size, int index, int& step) {
    int largest = index; // Инициализируем наибольший элемент как корень
    int left_index = 2 * index + 1; // Левый потомок
    int right_index = 2 * index + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left_index < array_size && array[left_index] > array[largest])
        largest = left_index;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right_index < array_size && array[right_index] > array[largest])
        largest = right_index;

    // Если наибольший элемент не является корнем
    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;

        if (step <= 1)
            return false;
        // Применяем просеивание вниз рекурсивно для затронутой под-пирамиды
        heapify(array, array_size, largest, step);
    }

    return true;
}

// Основная функция для сортировки массива с использованием пирамиды
void heapSort(QVector<int>& array, int& step) {
    // Построение пирамиды (перегруппировка массива)
    for (int index = array.size() / 2 - 1; index >= 0; index--)
        heapify(array, array.size(), index);

    // Извлечение элементов из пирамиды по одному и перемещение их в конец
    for (int index = array.size() - 1; index >= 0; index--) {
        int temp = array[index];
        array[index] = array[0];
        array[0] = temp; // Перемещаем текущий корень в конец

        if (step == 0 || --step == 0)
            return;
        if (!heapify(array, index, 0, step))
            return;
    }
}
//sort&1&20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
