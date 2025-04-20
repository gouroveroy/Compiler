#include <bits/stdc++.h>

using namespace std;

class Hash
{
public:
    static uint64_t SDBMHash(string str, int numberOfBuckets)
    {
        uint64_t hash = 0;
        int len = str.length();

        for (int i = 0; i < len; i++)
        {
            hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % numberOfBuckets;
        }

        return hash;
    }
};
