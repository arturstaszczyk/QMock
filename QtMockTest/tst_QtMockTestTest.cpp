#include <QString>
#include <QtTest>

#include "MockTester.h"

class QtMockTest : public QObject
{
    Q_OBJECT

public:
    QtMockTest(){}

private Q_SLOTS:
    void testCallsMade();
    void testReset();
    void testArgsStored();
    void testArgsStoredReset();
    void testReturnValues();
    void testAddReturnValues();
    void testResetReturnValues();
};

void QtMockTest::testCallsMade()
{
    MockTester tester;
    tester.call1();

    QCOMPARE(tester.calls().count(), 1);
    QStringList expectedCalls {
        "call1"
    };
    QCOMPARE(tester.calls(), expectedCalls);

    tester.call2();

    QCOMPARE(tester.calls().count(), 2);
    expectedCalls = QStringList {
        "call1",
        "call2"
    };
    QCOMPARE(tester.calls(), expectedCalls);

    QCOMPARE(tester.callArgs("call1").count(), 0);
    QCOMPARE(tester.callArgs("call2").count(), 0);
}

void QtMockTest::testReset()
{
    MockTester tester;
    tester.call1();
    tester.reset();
    QCOMPARE(tester.calls().count(), 0);

    tester.call2();
    QCOMPARE(tester.calls().count(), 1);
    QStringList expectedCalls {
        "call2"
    };
    QCOMPARE(tester.calls(), expectedCalls);
}

void QtMockTest::testArgsStored()
{
    MockTester tester;

    tester.call3(5, 'a');
    QCOMPARE(tester.calls().count(), 1);
    QVariantList expectedArgs { QVariant(5), QVariant('a') };
    QCOMPARE(tester.callArgs("call3"), expectedArgs);
}

void QtMockTest::testArgsStoredReset()
{
    MockTester tester;

    tester.call3(5, 'a');
    tester.reset();
    QCOMPARE(tester.callArgs("call3").count(), 0);
}

void QtMockTest::testReturnValues()
{
    MockTester tester;

    QVariantList returnValues { 1, 2, 3 };
    tester.returnValues("call4", returnValues);

    QCOMPARE(tester.call4(), returnValues[0].toInt());
    QCOMPARE(tester.call4(), returnValues[1].toInt());
    QCOMPARE(tester.call4(), returnValues[2].toInt());
    QCOMPARE(tester.call4(), 0);
}

void QtMockTest::testAddReturnValues()
{
    MockTester tester;

    QVariantList returnValues { 1, 2 };
    tester.returnValues("call4", returnValues);

    QCOMPARE(tester.call4(), 1);
    QCOMPARE(tester.call4(), 2);
    QCOMPARE(tester.call4(), 0);

    returnValues = QVariantList { 3, 4 };
    tester.returnValues("call4", returnValues);
    QCOMPARE(tester.call4(), 3);

    returnValues = QVariantList { 5, 6 };
    tester.returnValues("call4", returnValues);
    QCOMPARE(tester.call4(), 4);
    QCOMPARE(tester.call4(), 5);
    QCOMPARE(tester.call4(), 6);
}

void QtMockTest::testResetReturnValues()
{
    MockTester tester;

    QVariantList returnValues { 1, 2 };
    tester.returnValues("call4", returnValues);
    QCOMPARE(tester.call4(), 1);
    tester.reset();

    QCOMPARE(tester.call4(), 0);
    QCOMPARE(tester.call4(), 0);
}

QTEST_APPLESS_MAIN(QtMockTest)

#include "tst_QtMockTestTest.moc"
