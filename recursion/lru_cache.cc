#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

template <typename K, typename T>
struct LRUCacheEntry
{
    K key;
    T data;
    LRUCacheEntry *prev;
    LRUCacheEntry *next;
};

template <typename K, typename T>
class LRUCache
{
public:
    LRUCache(size_t sz) :head(NULL), tial(NULL) {
        entries = new LRUCacheEntry<K, T>[sz];
        for (int i = 0; i < sz; i++) {
            freeEntries.push_back(entries + i);
        }
    }

    ~LRUCache() { delete[] entries; }

    bool containsKey(K key) { return _m.find(key) != _m.end(); }

    void put(K key, T data) {
        LRUCacheEntry<K, T> *entry;

        if (_m.find(key) != _m.end()) return;

        if (freeEntries.size() > 0) {
            entry = freeEntries.back();
            freeEntries.pop_back();
        } else {
            entry = tail;
            if (tail->prev != NULL) tail->prev->next = NULL;
            _m.erase(entry->key);
        }

        _m[key] = entry;
        entry->key = key;
        entry->data = data;
        entry->next = head;
        entry->prev = NULL;

        if (head != NULL) {
            head->prev = entry;
        }

        head = entry;
    }

    T get(K key) {
        LRUCacheEntry<K, T> *entry = _m[key];

        if (entry != head) {
            if (entry->next != NULL) {
                entry->next->prev = entry->prev;
            }

            entry->prev->next = entry->next;
            if (entry == tail) tail = entry->prev;

            entry->next = head;
            entry->prev = NULL;
            head = entry;
        }
        return entry->data;
    }

    void print() {
        LRUCacheEntry<K, T> *entry = head;
        while (entry != NULL) {
            cout << entry->data << " ";
            entry = entry->next;
        }
        cout << endl;
    }

private:
    hash_map<K, LRUCacheEntry<K, T> *> _m;
    LRUCacheEntry<K, T> *head, *tail, *entries;
    vector<LRUCacheEntry<K, T> &> freeEntries;
}

int main()
{
    LRUCache<int, int> cache(3);

    cache.put(3, 3);
    cache.put(4, 4);
    cache.put(5, 5);

    cache.print();

    cache.get(3);
    cache.print();
    return 0;
}
