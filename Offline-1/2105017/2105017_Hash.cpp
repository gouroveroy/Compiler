#include "2105017_Hash.h"

using namespace std;

function<unsigned int(string, unsigned int)> Hash::getHashFunction(const string &name)
{
    if (name == "sdbm")
    {
        hashFunction = &SDBMHash;
    }
    else if (name == "djb2")
    {
        hashFunction = &DJB2Hash;
    }
    else if (name == "bkdr")
    {
        hashFunction = &BKDRHash;
    }
    else if (name == "rs")
    {
        hashFunction = &RSHash;
    }
    else if (name == "js")
    {
        hashFunction = &JSHash;
    }
    else if (name == "elf")
    {
        hashFunction = &ELFHash;
    }
    else if (name == "ap")
    {
        hashFunction = &APHash;
    }
    else if (name == "pjw")
    {
        hashFunction = &PJWHash;
    }
    else if (name == "fnv")
    {
        hashFunction = &FNVHash;
    }
    else if (name == "dek")
    {
        hashFunction = &DEKHash;
    }
    else if (name == "bp")
    {
        hashFunction = &BPHash;
    }
    else
    {
        hashFunction = &SDBMHash;
    }
    return hashFunction;
}

/**
 * SDBM Hash Function
 * Source: https://www.programmingalgorithms.com/algorithm/sdbm-hash/cpp/
 */
unsigned int Hash::SDBMHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 0;
    for (char ch : str)
    {
        hash = ((unsigned int)ch + (hash << 6) + (hash << 16) - hash) % numberOfBuckets;
    }
    return hash;
}

/**
 * DJB2 Hash Function by Dan Bernstein
 * Source: https://web.archive.org/web/20120623170445/http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int Hash::DJB2Hash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 5381;
    for (char ch : str)
    {
        hash = ((hash << 5) + hash + (unsigned int)ch) % numberOfBuckets; // hash * 33 + ch
    }
    return hash;
}

/**
 * BKDR Hash Function
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::BKDRHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int seed = 131; // 31, 131, 1313, 13131, etc.
    unsigned int hash = 0;

    for (char ch : str)
    {
        hash = (hash * seed + (unsigned int)ch) % numberOfBuckets;
    }
    return hash;
}

/**
 * RS Hash Function by Robert Sedgwicks
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::RSHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    for (char ch : str)
    {
        hash = (hash * a + (unsigned int)ch) % numberOfBuckets;
        a = (a * b) % numberOfBuckets;
    }
    return hash;
}

/**
 * JS Hash Function by Justin Sobel
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::JSHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 1315423911;
    for (char ch : str)
    {
        hash ^= ((hash << 5) + (unsigned int)ch + (hash >> 2)) % numberOfBuckets;
    }
    return hash;
}

/**
 * ELF Hash Function
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::ELFHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (char ch : str)
    {
        hash = (hash << 4) + (unsigned int)ch;
        if ((x = hash & 0xF0000000))
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return hash % numberOfBuckets;
}

/**
 * AP Hash Function by Arash Partow
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::APHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 0xAAAAAAAA;
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((i & 1) == 0) // Odd index
        {
            hash ^= ((hash << 7) ^ (unsigned int)str[i] ^ (hash >> 3));
        }
        else // Even index
        {
            hash ^= (~((hash << 11) + (unsigned int)str[i] + (hash >> 5)));
        }
    }
    return hash % numberOfBuckets;
}

/**
 * PJW Hash Function by Peter J. Weinberger
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::PJWHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 0;
    unsigned int highBits = 0;
    unsigned int x = 0;

    for (char ch : str)
    {
        hash = (hash << 4) + (unsigned int)ch;
        if ((x = hash & 0xF0000000))
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return hash % numberOfBuckets;
}

/**
 * FNV Hash Function
 * Source: http://www.isthe.com/chongo/tech/comp/fnv/
 */
unsigned int Hash::FNVHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 2166136261u;
    for (char ch : str)
    {
        hash ^= (unsigned int)ch;
        hash *= 16777619;
    }
    return hash % numberOfBuckets;
}

/**
 * DEK Hash Function
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::DEKHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = str.length();
    for (char ch : str)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ (unsigned int)ch;
    }
    return hash % numberOfBuckets;
}

/**
 * BP Hash Function
 * Source: https://www.partow.net/programming/hashfunctions/
 */
unsigned int Hash::BPHash(const string &str, unsigned int numberOfBuckets)
{
    unsigned int hash = 0;
    for (char ch : str)
    {
        hash = (hash << 7) ^ (unsigned int)ch;
    }
    return hash % numberOfBuckets;
}

unsigned int (*Hash::hashFunction)(const string &, unsigned int) = &Hash::SDBMHash; // Default hash function
