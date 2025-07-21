#include <iostream>
#include <string>
#include <memory>
#include "2105017_function_info.cpp"

using namespace std;

class SymbolInfo
{
    string symbolName;
    string symbolType;
    string declaredType;
    string dataType;
    shared_ptr<SymbolInfo> nextSymbol;
    shared_ptr<FunctionInfo> functionInfo;
    int offset;
    bool isParameter;

public:
    SymbolInfo(string symbolName, string symbolType, shared_ptr<SymbolInfo> nextSymbol = nullptr)
    {
        this->symbolName = symbolName;
        this->symbolType = symbolType;
        this->nextSymbol = nextSymbol;
        this->declaredType = "";
        this->dataType = "variable";
        this->functionInfo = nullptr;
        this->offset = 0;
        this->isParameter = false;
    }

    ~SymbolInfo() = default;

    string getSymbolName() const
    {
        return symbolName;
    }

    void setSymbolName(const string &symbolName)
    {
        this->symbolName = symbolName;
    }

    string getSymbolType() const
    {
        return symbolType;
    }

    void setSymbolType(const string &symbolType)
    {
        this->symbolType = symbolType;
    }

    shared_ptr<SymbolInfo> getNextSymbol() const
    {
        return nextSymbol;
    }

    void setNextSymbol(shared_ptr<SymbolInfo> nextSymbol)
    {
        this->nextSymbol = nextSymbol;
    }

    void setDeclaredType(const string &type)
    {
        declaredType = type;
    }

    string getDeclaredType() const
    {
        return declaredType;
    }

    void setDataType(const string &dt)
    {
        dataType = dt;
    }

    string getDataType() const
    {
        return dataType;
    }

    void setFunctionInfo(shared_ptr<FunctionInfo> funcInfo)
    {
        this->functionInfo = funcInfo;
    }

    shared_ptr<FunctionInfo> getFunctionInfo() const
    {
        return functionInfo;
    }

    void setOffset(int off)
    {
        offset = off;
    }

    int getOffset() const
    {
        return offset;
    }

    void setIsParameter(bool param)
    {
        isParameter = param;
    }

    bool getIsParameter() const
    {
        return isParameter;
    }
};