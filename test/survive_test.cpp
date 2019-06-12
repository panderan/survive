#include <iostream>
#include <QtTest/QtTest>
#include <QString>
#include "survive.h"

using namespace std;

typedef Matrix<int, 6, 6> Matrix6i;

class TestSur : public QObject
{
    Q_OBJECT

    private slots:
        void TestConstructor();
        void TestOneStep();
        void TestTwoStep();
};


void TestSur::TestConstructor()
{
    Survive s(4,4);
    QCOMPARE(s.data.isApprox(Matrix6i::Zero()), true);
}

void TestSur::TestOneStep()
{
    Survive s(4,4);
    s.setAliveCell(1,1);
    s.setAliveCell(1,2);
    int ret = s.calculatorOneCell(1,1);

    QCOMPARE(ret, 2);
}
void TestSur::TestTwoStep()
{
    Survive s(4,4);
    s.setAliveCell(2,1);
    s.setAliveCell(2,2);
    s.setAliveCell(2,3);
    s.setAliveCell(3,2);
    s.setAliveCell(3,3);
    Survive o(4,4);
    s.setAliveCell(1,2);
    s.setAliveCell(2,1);
    s.setAliveCell(2,3);
    s.setAliveCell(3,3);

    /*QCOMPARE(o.isApprox(data.block<4,4>(1,1)), true); */
}

QTEST_MAIN(TestSur)
#include "survive_test.moc"
