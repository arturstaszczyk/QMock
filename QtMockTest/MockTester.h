#ifndef MOCKTESTER
#define MOCKTESTER

#include "QtMock.h"

class MockTester : public QtMock
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
        MOCK_CALL; MOCK_ARG(MOCK_FNAME, arg1); MOCK_ARG(MOCK_FNAME, arg2);
    }
};

#endif // MOCKTESTER

