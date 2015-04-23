
class UnionFind():
    def __init__(self, size):
        self.data = [-1] * size

    def union_set(self, x, y):
        x = self.root(x)
        y = self.root(y)

        if (x != y):
            if (self.data[y] < self.data[x]):
                x, y = y, x

            self.data[x] += self.data[y]
            self.data[y] = x

        return x != y

    def find_set(self, x, y):
        return self.root(x) == self.root(y)

    def root(self, x):
        if self.data[x] < 0:
            return x
        else:
            self.data[x] = self.root(self.data[x])
            return self.data[x]

    def size(self, x):
        return -self.data[self.root(x)]


if __name__ == "__main__":
    uf = UnionFind(10)

    uf.union_set(1, 2)
    uf.union_set(2, 3)

    print(uf.root(3))
