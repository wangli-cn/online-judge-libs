//Hash函数  数据1   数据2   数据3   数据4   数据1得分   数据2得分   数据3得分   数据4得分   平均分
//BKDRHash  2   0   4774    481 96.55   100 90.95   82.05   92.64
//APHash    2   3   4754    493 96.55   88.46   100 51.28   86.28
//DJBHash   2   2   4975    474 96.55   92.31   0   100 83.43
//JSHash    1   4   4761    506 100 84.62   96.83   17.95   81.94
//RSHash    1   0   4861    505 100 100 51.58   20.51   75.96
//SDBMHash  3   2   4849    504 93.1    92.31   57.01   23.08   72.41
//PJWHash   30  26  4878    513 0   0   43.89   0   21.95
//ELFHash   30  26  4878    513 0   0   43.89   0   21.95

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; ++i)

template <typename T>
struct Slot {
    T data;
    Slot(T data) :data(data) {}
};

int M = 20627;

unsigned DJBHash(const char *str)
{
    unsigned hash = 5381;

    while (*str) {
        hash += (hash << 5) + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

unsigned SDBMHash(const char *str)
{
    unsigned hash = 0;

    while (*str) {
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }

    return (hash & 0x7FFFFFFF);
}

unsigned RSHash(const char *str)
{
    unsigned b = 378551;
    unsigned a = 63689;
    unsigned hash = 0;

    while (*str) {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash & 0x7FFFFFFF);
}

unsigned JSHash(const char *str)
{
    unsigned hash = 1315423911;

    while (*str) {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }

    return (hash & 0x7FFFFFFF);
}

unsigned BKDRHash(const char *str)
{
    unsigned seed = 131;
    unsigned hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}


unsigned APHash(const char *str)
{
    unsigned hash = 0;
    int i;

    for (i = 0; *str; i++) {
        if ((i & 1) == 0) {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        } else {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
}


unsigned hash(const string &s)
{
    return (BKDRHash(s.c_str()) % M);
}

int main()
{
    list< Slot<int> > hashTable[M];
    vector<string> keys;

    REP(i, keys.size()) {
        hashTable[hash(keys[i])].push_back(Slot<int>(1));
    }
    return 0;
}
