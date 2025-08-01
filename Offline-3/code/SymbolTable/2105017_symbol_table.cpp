#include <bits/stdc++.h>
#include "2105017_scope_table.cpp"

using namespace std;

class SymbolTable
{
    int numberOfBuckets;
    shared_ptr<ScopeTable> currentScope;
    function<unsigned int(string, unsigned int)> hashFunction;

    bool isPrintable = false;
    ofstream &logFile;

public:
    SymbolTable(int n, function<unsigned int(string, unsigned int)> hashFunction, ofstream &logFile)
        : logFile(logFile)
    {
        numberOfBuckets = n;
        currentScope = nullptr;
        this->hashFunction = hashFunction;
        enterScope();
    }

    ~SymbolTable()
    {
        while (currentScope != nullptr)
        {
            currentScope = currentScope->getParentScope();
        }
    }

    shared_ptr<ScopeTable> getCurrentScope()
    {
        return currentScope;
    }

    void setCurrentScope(shared_ptr<ScopeTable> currentScope)
    {
        this->currentScope = currentScope;
    }

    int getNumberOfBuckets()
    {
        return numberOfBuckets;
    }

    void setNumberOfBuckets(int numberOfBuckets)
    {
        this->numberOfBuckets = numberOfBuckets;
    }

    void enterScope()
    {
        shared_ptr<ScopeTable> newScope = make_shared<ScopeTable>(numberOfBuckets, logFile, currentScope, hashFunction);
        currentScope = newScope;
        if (isPrintable)
        {
            cout << "\tScopeTable# " << currentScope->getScopeId() << " created" << endl;
        }
    }

    void exitScope()
    {
        if (currentScope != nullptr)
        {
            currentScope->setNumberofChildren(currentScope->getNumberOfChildren() + 1);
            string exitingId = currentScope->getScopeId();
            currentScope = currentScope->getParentScope();
            if (isPrintable)
            {
                cout << "\tScopeTable# " << exitingId << " removed" << endl;
            }
        }
    }

    bool Insert(string symbolName, string symbolType)
    {
        if (currentScope != nullptr)
        {
            return currentScope->Insert(symbolName, symbolType);
        }
        return false;
    }

    bool Remove(string symbolName)
    {
        if (currentScope != nullptr)
        {
            return currentScope->Delete(symbolName);
        }
        return false;
    }

    shared_ptr<SymbolInfo> LookUp(string symbolName)
    {
        shared_ptr<ScopeTable> scope = currentScope;
        while (scope != nullptr)
        {
            shared_ptr<SymbolInfo> symbol = scope->LookUp(symbolName).first;
            if (symbol != nullptr)
            {
                return symbol;
            }
            scope = scope->getParentScope();
        }
        if (isPrintable)
        {
            cout << "\t'" << symbolName << "' not found in any of the ScopeTables" << endl;
        }
        return nullptr;
    }

    void PrintCurrentScopeTable()
    {
        if (currentScope != nullptr)
        {
            currentScope->Print();
        }
    }

    void PrintAllScopeTable()
    {
        shared_ptr<ScopeTable> scope = currentScope;
        int count = 1;
        while (scope != nullptr)
        {
            scope->Print();
            scope = scope->getParentScope();
            count++;
        }
        logFile << endl;
    }
};
