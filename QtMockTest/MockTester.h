#ifndef MOCKTESTER
#define MOCKTESTER

#include "QtMock.h"

class MockTester : public QtMockExt::QtMock
{
public:
    MockTester()
    {
    }

    void call1()
    {
        MOCK_CALL;
    }

    void call2()
    {
        MOCK_CALL;
    }

    void call3(int arg1, char arg2)
    {
        MOCK_CALL; MOCK_ARG(arg1); MOCK_ARG(arg2);
    }

    int call4()
    {
        return RETURN_VALUES(int);
    }

    QString call5()
    {
        return RETURN_VALUES(QString);
    }
};

#endif // MOCKTESTER

