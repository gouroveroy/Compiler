#ifndef HASH_H
#define HASH_H

#include <string>
#include <functional>

using namespace std;

class Hash
{
public:
    static unsigned int SDBMHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int DJB2Hash(const string &str, unsigned int numberOfBuckets);
    static unsigned int BKDRHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int RSHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int JSHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int ELFHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int APHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int PJWHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int FNVHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int DEKHash(const string &str, unsigned int numberOfBuckets);
    static unsigned int BPHash(const string &str, unsigned int numberOfBuckets);

    static unsigned int (*hashFunction)(const string &, unsigned int); // function pointer
    static function<unsigned int(string, unsigned int)> getHashFunction(const string &name);
};

#endif
