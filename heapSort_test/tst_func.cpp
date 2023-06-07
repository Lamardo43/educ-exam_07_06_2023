#include <QtTest>
#include "../Server/functions.h"
// add necessary includes here

class func : public QObject
{
    Q_OBJECT

public:
    func();
    ~func();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();
    void test_case9();
    void test_case10();

};

func::func()
{

}

func::~func()
{

}

void func::test_case1()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {5, 1, 4, 4, 2, 1, 3, 2, 3, 5};
    int step = 2;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case2()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {4, 1, 4, 3, 2, 1, 3, 2, 5, 5};
    int step = 3;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case3()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {4, 3, 1, 2, 2, 1, 3, 4, 5, 5};
    int step = 4;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case4()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {3, 1, 3, 2, 2, 1, 4, 4, 5, 5};
    int step = 5;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case5()
{
    QVector<int> array = {3, 4, 5, 2, 3, 5, 9, 8, 4, 5, 6};
    QVector<int> ans_array = {5, 4, 2, 4, 3, 3, 5, 5, 6, 8, 9};
    int step = 5;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case6()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {3, 2, 1, 1, 2, 3, 4, 4, 5, 5};
    int step = 6;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case7()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int step = 80;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case8()
{
    QVector<int> array = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int step = 9;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case9()
{
    QVector<int> array = {4, 5, 6, 23, 5, 8, 9, 5};
    QVector<int> ans_array = {5, 4, 5, 5, 6, 8, 9, 23};
    int step = 7;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}
void func::test_case10()
{
    QVector<int> array = {2, 3, 4, 7, 5, 2, 9, 0, 66, 4, 3};
    QVector<int> ans_array = {7, 4, 4, 3, 5, 2, 3, 0, 2, 9, 66};
    int step = 3;
    heapSort(array, step);
    QVERIFY(array == ans_array);
}


QTEST_APPLESS_MAIN(func)

#include "tst_func.moc"
