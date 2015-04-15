import queue

INF = 1000000000

class Edge():
    def __init__(self, src, dst, weight):
        self.src = src
        self.dst = dst
        self.weight = weight

    def __lt__(self, other):
        if self.weight != other.weight:
            return self.weight < other.weight
        elif self.dst != other.dst:
            return self.dst < other.dst
        else:
            return self.src < other.src


def dijkstra(g, s):
    n = len(g)
    dist = [INF] * n
    dist[s] = 0

    prev = [-1] * n

    Q = queue.PriorityQueue()
    Q.put(Edge(-2, s, 0))
    while not Q.empty():
        e = Q.get()

        if prev[e.dst] != -1:
            continue

        prev[e.dst] = e.src
        for f in g[e.dst]:
            if dist[f.dst] > e.weight + f.weight:
                dist[f.dst] = e.weight + f.weight
                Q.put(Edge(f.src, f.dst, e.weight + f.weight))

    return (dist, prev)


if __name__ == "__main__":
    n, m = map(int, input().split())
    g = [[]] * n
    for i in range(0, m):
        a1, a2, w = map(int, input().split())
        g[a1].append(Edge(a1, a2, w))

    dist, prev = dijkstra(g, 0)
    print(dist)
