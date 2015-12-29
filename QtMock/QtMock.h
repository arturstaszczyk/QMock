#ifndef QTMOCK_H
#define QTMOCK_H

#include <QStringList>
#include <QVariantList>

#define MOCK_FNAME __FUNCTION__
#define MOCK_CALL mCalls.append(MOCK_FNAME)
#define MOCK_ARG(call, x) addCallArg(call, x)

class QtMock
{
public:

    void reset()
    {
        mCalls.clear();
        mCallArgs.clear();
    }

    const QStringList& calls() const { return mCalls; }

    bool hasExactlyOneCall(QString call) const
    {
        return mCalls.filter(call, Qt::CaseSensitive).count() == 1;
    }

    bool hasCall(QString call) const
    {
        return mCalls.filter(call, Qt::CaseSensitive).count() > 1;
    }

    bool hasCalls(QString call, int times) const
    {
        return mCalls.filter(call, Qt::CaseSensitive).count() == times;
    }

//    void returnValues(QString method, QVariant value)
//    {

//    }

    const QVariantList& callArgs(QString callName)
    {
        return mCallArgs.value(callName).toList();
    }

protected:
    void addCallArg(QString callName, QVariant arg)
    {
        if(!mCallArgs.contains(callName))
            mCallArgs.insert(callName, QVariantList());

        auto argsList = mCallArgs[callName].toList();
        argsList.append(arg);
        mCallArgs[callName] = argsList;
    }

protected:
    QStringList mCalls;
    QVariantMap mCallArgs;
    QVariantMap mReturnValue;
};

#endif // QTMOCK_H
