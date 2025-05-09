#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include "SymbolInfo.cpp"
#include "Hash.cpp"

using namespace std;

class ScopeTable
{
    int scopeId;
    int numberOfBuckets;
    shared_ptr<ScopeTable> parentScope;
    shared_ptr<SymbolInfo> *table;
    function<unsigned int(string, unsigned int)> hashFunction;

    bool isPrintable = true;
    int totalCollisions = 0;

public:
    ScopeTable(int numberOfBuckets, int scopeId, shared_ptr<ScopeTable> parentScope = nullptr, function<unsigned int(string, int)> hashFunc = Hash::getHashFunction("SDBM"))
        : numberOfBuckets(numberOfBuckets),
          scopeId(scopeId),
          parentScope(parentScope),
          hashFunction(hashFunc)
    {
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

    int getScopeId()
    {
        return scopeId;
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

    shared_ptr<SymbolInfo> LookUp(string symbolName)
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
                return currentSymbol;
            }
            currentSymbol = currentSymbol->getNextSymbol();
            index++;
        }
        return nullptr;
    }

    bool Insert(string symbolName, string symbolType)
    {
        bool originalPrintable = isPrintable;
        isPrintable = false;
        shared_ptr<SymbolInfo> existingSymbol = LookUp(symbolName);
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
        shared_ptr<SymbolInfo> existingSymbol = LookUp(symbolName);
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

    void Print(int tabCount)
    {
        if (isPrintable)
        {
            cout << "\tScopeTable# " << scopeId << endl;
            for (int i = 0; i < numberOfBuckets; i++)
            {
                for (int j = 0; j < tabCount; j++)
                    cout << "\t";
                cout << i + 1 << "--> ";
                shared_ptr<SymbolInfo> currentSymbol = table[i];
                while (currentSymbol != nullptr)
                {
                    cout << "<" << currentSymbol->getSymbolName() << "," << currentSymbol->getSymbolType() << "> ";
                    currentSymbol = currentSymbol->getNextSymbol();
                }
                cout << endl;
            }
        }
    }
};
