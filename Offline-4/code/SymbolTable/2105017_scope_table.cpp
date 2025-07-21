#include <bits/stdc++.h>
#include "2105017_symbol_info.cpp"
#include "2105017_Hash.h"

using namespace std;

class ScopeTable
{
    string scopeId;
    int numberOfBuckets;
    shared_ptr<ScopeTable> parentScope;
    shared_ptr<SymbolInfo> *table;
    function<unsigned int(string, unsigned int)> hashFunction;

    bool isPrintable = false;
    int totalCollisions = 0;
    int numberOfChildren;
    ofstream &logFile;

public:
    ScopeTable(int numberOfBuckets, ofstream &logFile, shared_ptr<ScopeTable> parentScope = nullptr, function<unsigned int(string, int)> hashFunc = Hash::SDBMHash)
        : numberOfBuckets(numberOfBuckets),
          parentScope(parentScope),
          hashFunction(hashFunc),
          logFile(logFile)
    {
        this->numberOfChildren = 0;
        if (this->parentScope != nullptr)
        {
            this->scopeId = parentScope->getScopeId() + "." + to_string(parentScope->getNumberOfChildren() + 1);
            parentScope->setNumberofChildren(parentScope->getNumberOfChildren() + 1);
        }
        else
        {
            this->scopeId = "1";
        }
        table = new shared_ptr<SymbolInfo>[numberOfBuckets];
        for (int i = 0; i < numberOfBuckets; i++)
        {
            table[i] = nullptr;
        }
    }

    ~ScopeTable()
    {
        for (int i = 0; i < numberOfBuckets; i++)
        {
            if (table[i] != nullptr)
            {
                table[i].reset();
            }
        }
        delete[] table;
    }

    int getNumberOfChildren()
    {
        return numberOfChildren;
    }

    void setNumberofChildren(int numberOfChildren)
    {
        this->numberOfChildren = numberOfChildren;
    }

    int getNumberOfBuckets()
    {
        return numberOfBuckets;
    }

    bool getIsPrintable()
    {
        return isPrintable;
    }

    void setIsPrintable(bool isPrintable)
    {
        this->isPrintable = isPrintable;
    }

    int getTotalCollisions()
    {
        return totalCollisions;
    }

    void setScopeId(string scopeId)
    {
        this->scopeId = scopeId;
    }

    string getScopeId()
    {
        return scopeId;
    }

    void setTotalCollisions(int totalCollisions)
    {
        this->totalCollisions = totalCollisions;
    }

    shared_ptr<ScopeTable> getParentScope()
    {
        return parentScope;
    }

    void setParentScope(shared_ptr<ScopeTable> parentScope)
    {
        this->parentScope = parentScope;
    }

    int getTableIndex(string symbolName)
    {
        unsigned int hash = hashFunction(symbolName, numberOfBuckets);
        return hash % numberOfBuckets;
    }

    pair<shared_ptr<SymbolInfo>, pair<int, int>> LookUp(string symbolName)
    {
        int hashValue = getTableIndex(symbolName);
        shared_ptr<SymbolInfo> currentSymbol = table[hashValue];
        int index = 1;
        while (currentSymbol != nullptr)
        {
            if (currentSymbol->getSymbolName() == symbolName)
            {
                if (isPrintable)
                {
                    cout << "\t'" << symbolName << "' found in ScopeTable# " << scopeId << " at position " << hashValue + 1 << ", " << index << endl;
                }
                return {currentSymbol, {hashValue + 1, index}};
            }
            currentSymbol = currentSymbol->getNextSymbol();
            index++;
        }
        return {nullptr, {hashValue + 1, index}};
    }

    bool Insert(string symbolName, string symbolType)
    {
        bool originalPrintable = isPrintable;
        isPrintable = false;
        auto lookupResult = LookUp(symbolName);
        shared_ptr<SymbolInfo> existingSymbol = lookupResult.first;
        isPrintable = originalPrintable;

        if (existingSymbol == nullptr)
        {
            int hashValue = getTableIndex(symbolName);
            shared_ptr<SymbolInfo> newSymbol = make_shared<SymbolInfo>(symbolName, symbolType);
            shared_ptr<SymbolInfo> currentSymbol = table[hashValue];
            int index = 1;
            if (currentSymbol == nullptr)
            {
                table[hashValue] = newSymbol;
            }
            else
            {
                totalCollisions++;
                while (currentSymbol->getNextSymbol() != nullptr)
                {
                    currentSymbol = currentSymbol->getNextSymbol();
                    index++;
                }
                currentSymbol->setNextSymbol(newSymbol);
                index++;
            }
            if (isPrintable)
            {
                cout << "\tInserted in ScopeTable# " << scopeId << " at position " << hashValue + 1 << ", " << index << endl;
            }
            return true;
        }
        else
        {
            if (isPrintable)
            {
                cout << "\t'" << symbolName << "' already exists in the current ScopeTable" << endl;
            }
            return false;
        }
    }

    bool Delete(string symbolName)
    {
        bool originalPrintable = isPrintable;
        isPrintable = false;
        shared_ptr<SymbolInfo> existingSymbol = LookUp(symbolName).first;
        isPrintable = originalPrintable;

        if (existingSymbol != nullptr)
        {
            int hashValue = getTableIndex(symbolName);
            shared_ptr<SymbolInfo> currentSymbol = table[hashValue];
            shared_ptr<SymbolInfo> previousSymbol = nullptr;
            int index = 1;
            while (currentSymbol != nullptr)
            {
                if (currentSymbol->getSymbolName() == symbolName)
                {
                    if (previousSymbol == nullptr)
                    {
                        table[hashValue] = currentSymbol->getNextSymbol();
                    }
                    else
                    {
                        previousSymbol->setNextSymbol(currentSymbol->getNextSymbol());
                    }
                    if (isPrintable)
                    {
                        cout << "\tDeleted '" << symbolName << "' from ScopeTable# " << scopeId << " at position " << hashValue + 1 << ", " << index << endl;
                    }
                    return true;
                }
                previousSymbol = currentSymbol;
                currentSymbol = currentSymbol->getNextSymbol();
                index++;
            }
        }
        if (isPrintable)
        {
            cout << "\tNot found in the current ScopeTable" << endl;
        }
        return false;
    }

    void Print()
    {
        logFile << "ScopeTable # " << scopeId << endl;
        for (int i = 0; i < numberOfBuckets; i++)
        {
            if (table[i] == nullptr)
            {
                continue;
            }
            logFile << i << " --> ";
            shared_ptr<SymbolInfo> currentSymbol = table[i];
            while (currentSymbol != nullptr)
            {
                logFile << "< " << currentSymbol->getSymbolName() << " : " << currentSymbol->getSymbolType() << " >";
                currentSymbol = currentSymbol->getNextSymbol();
            }
            logFile << endl;
        }
    }
};
