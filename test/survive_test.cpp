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
};


void TestSur::TestConstructor()
{
    Survive s(4,4);
    QCOMPARE(s.data.isApprox(Matrix4i::Zero()), true);
}


QTEST_MAIN(TestSur)
#include "survive_test.moc"
