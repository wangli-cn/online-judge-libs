#include <iostream>
#include <vector>

class UnionFind
{
public:
    std::vector<int> data;

    UnionFind() = delete;
    explicit UnionFind(int size) :data(size, -1) {}

    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};

int main(void)
{
    UnionFind uf(10);
    uf.unionSet(1, 2);
    uf.unionSet(3, 4);
    uf.unionSet(1, 5);

    std::cout << uf.size(1) << std::endl;
    std::cout << uf.root(5) << std::endl;
    return 0;
}
