#include <iostream>
#include <string>

using namespace std;

class FunctionInfo
{
    string returnType;
    string *parameterTypes;
    int parameterCount;

public:
    FunctionInfo(const string &returnType, const string *params, int paramCount)
        : returnType(returnType), parameterCount(paramCount)
    {
        parameterTypes = new string[paramCount];
        for (int i = 0; i < paramCount; ++i)
        {
            parameterTypes[i] = params[i];
        }
    }

    ~FunctionInfo()
    {
        delete[] parameterTypes;
    }

    string getReturnType() const
    {
        return returnType;
    }

    int getParameterCount() const
    {
        return parameterCount;
    }

    string getParameterType(int idx) const
    {
        if (idx >= 0 && idx < parameterCount)
        {
            return parameterTypes[idx];
        }
        return "";
    }

    string *getParameterTypes() const
    {
        return parameterTypes;
    }

    void setReturnType(const string &type)
    {
        returnType = type;
    }

    void addParameterType(const string &type)
    {
        string *newParams = new string[parameterCount + 1];
        for (int i = 0; i < parameterCount; ++i)
        {
            newParams[i] = parameterTypes[i];
        }
        newParams[parameterCount] = type;
        delete[] parameterTypes;
        parameterTypes = newParams;
        parameterCount++;
    }

    void setParameterCount(int count)
    {
        parameterCount = count;
    }
};
