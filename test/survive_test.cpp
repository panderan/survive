#include <iostream>
#include <QtTest/QtTest>
#include <QString>
#include "survive.h"

using namespace std;

class TestSur : public QObject
{
    Q_OBJECT

    private slots:
        void TestConstructor();
        void TestOneStep();
};


void TestSur::TestConstructor()
{
    Survive s(4,4);
    QCOMPARE(s.data.isApprox(Matrix4i::Zero()), true);
}

void TestSur::TestOneStep()
{
    Survive s(4,4);
    s.setAliveCell(1,1);
    s.setAliveCell(1,2);
    int ret = s.calculatorOneCell(1,2);

    QCOMPARE(ret, 1);
}


QTEST_MAIN(TestSur)
#include "survive_test.moc"
