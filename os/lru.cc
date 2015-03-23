#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;


class LRUCache
{
    public:
        class CacheEntry
        {
            public:
                int key, value;
                explicit CacheEntry(int k, int v) :key(k), value(v) {}
        };

        explicit LRUCache(size_t sz) {
            m_capacity = sz;
        }
        ~LRUCache() {}

        void put(int key, int value) {
            if (m_map.find(key) == m_map.end()) {
                CacheEntry newItem(key, value);

                if (m_LRU_cache.size() >= m_capacity) {
                    m_map.erase(m_LRU_cache.back().key);
                    m_LRU_cache.pop_back();
                }

                m_LRU_cache.push_front(newItem);
                m_map[key] = m_LRU_cache.begin();
                return;
            }
        }

        int get(int key) {
            if (m_map.find(key) == m_map.end()) {
                return -1;
            }

            MoveToHead(key);
            return m_map[key]->value;
        }

    private:
        unordered_map<int, list<CacheEntry>::iterator > m_map;
        list<CacheEntry> m_LRU_cache;
        int m_capacity;

        void MoveToHead(int key)
        {
            auto updateEntry = *m_map[key];
            m_LRU_cache.erase(m_map[key]);
            m_LRU_cache.push_front(updateEntry);
            m_map[key] = m_LRU_cache.begin();
        }
};


int main(void)
{
    LRUCache C(10);

    for (int i = 1; i <= 20; i++) {
        C.put(i, i);
    }

    cout << C.get(20) << endl;

    return 0;
}
