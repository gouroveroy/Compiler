#include <iostream>
#include <string>
#include <memory>

using namespace std;

class SymbolInfo
{
    string symbolName;
    string symbolType;
    shared_ptr<SymbolInfo> nextSymbol;

public:
    SymbolInfo(string symbolName, string symbolType, shared_ptr<SymbolInfo> nextSymbol = nullptr)
    {
        this->symbolName = symbolName;
        this->symbolType = symbolType;
        this->nextSymbol = nextSymbol;
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
};
