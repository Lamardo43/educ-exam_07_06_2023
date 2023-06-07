#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QByteArray>
#include <QString>
#include <QList>
#include <QVector>

QByteArray parse(QByteArray mess);

QString sort(QList<QByteArray> &array_parts, int& step);

void heapify(QVector<int>& array, int array_size, int index);

bool heapify(QVector<int>& array, int array_size, int index, int& step);

void heapSort(QVector<int>& array, int& step);

#endif // FUNCTIONS_H
