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
    QList<QByteArray> array = {"1", "2", "3" "4", "5", "1", "4", "2", "3", "5"};
    QString ans_array = "5 1 4 4 2 1 3 2 3 5";
    int step = 2;
    QVERIFY(sort(array, step) == ans_array);
}

QTEST_APPLESS_MAIN(func)

#include "tst_func.moc"
