#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

const int M = 20627;

template <class T>
struct Slot {
    T data;
    Slot(T data) :data(data) {}
};

//djb2
unsigned int hash(const string &s)
{
    unsigned int key = 5381;
    for (string::const_iterator p = s.begin(); p != s.end(); ++p) {
        key = (((key << 5) + key) + *p) % M;
    }
    return key;
}

int main(void)
{
    list< Slot<int> > hashTable[M];
    vector<string> keys;

    keys.push_back(string("PHP"));
    keys.push_back(string("C++"));
    keys.push_back(string("MySQL"));
    keys.push_back(string("Python"));
    keys.push_back(string("Perl"));
    keys.push_back(string("CSS"));
    keys.push_back(string("Javascript"));

    for (int i = 0; i < keys.size(); ++i) {
        hashTable[hash(keys[i])].push_back(Slot<int>(rand()));
        cout << keys[i] << " goes to " << hash(keys[i]) << endl;
    }

    return 0;
}
