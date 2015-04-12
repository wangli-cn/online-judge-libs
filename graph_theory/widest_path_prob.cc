#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <queue>

class Edge
{
public:
    explicit Edge(int src, int dst, int capacity) :src(src), dst(dst), capacity(capacity) {}

    int src, dst;
    int capacity;
};

bool operator<(const Edge &a, const Edge &b)
{
    if (a.capacity != b.capacity) {
        return (a.capacity < b.capacity);
    } else if (a.src != b.src) {
        return (a.src < b.src);
    } else {
        return (a.dst < b.dst);
    }
}


using Graph = std::vector<std::vector<int> >;

void dijkstra(const Graph &g, int s, std::vector<int> &bottleneck, std::vector<int> &prev)
{
    int n = g.size();

    bottleneck.assign(n, std::numeric_limits<int>::max());
    prev.assign(n, -1);

    std::priority_queue<Edge> Q;

    Q.push(Edge(-2, s, std::numeric_limits<int>::max()));
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (prev[e.dst] != -1) continue;

        prev[e.dst] = e.src;
        for (int i = 0; i < n; i++) {
            if (g[e.dst][i] > 0) {
                if (bottleneck[i] == std::numeric_limits<int>::max() || bottleneck[i] < std::min(bottleneck[e.dst], g[e.dst][i])) {
                    bottleneck[i] = std::min(bottleneck[e.dst], g[e.dst][i]);
                    Q.push(Edge(e.dst, i, std::min(bottleneck[e.dst], g[e.dst][i])));
                }
            }
        }
    }
}


std::vector<int> build_path(std::vector<int> &prev, int t)
{
    std::vector<int> path;
    for (int u = t; u >= 0; u = prev[u]) {
        path.push_back(u);
    }
    std::reverse(path.begin(), path.end());
    return path;
}


int main()
{
    int n, q;
    std::cin >> n >> q;

    std::string s;
    int src, dst;
    Graph g(n, std::vector<int>(n, 0));

    for (int i = 1; i <= q; i++) {
        std::cin >> s >> src >> dst;

        src -= 1;
        dst -= 1;

        if (s == std::string("build")) {
            g[src][dst] = i;
            g[dst][src] = i;
        } else if (s == std::string("check")) {
            std::vector<int> bottleneck;
            std::vector<int> prev;

            dijkstra(g, src, bottleneck, prev);

            if (prev[dst] != -1 ) {
                std::cout << "YES " << bottleneck[dst] << std::endl;
                auto path = build_path(prev, dst);

                for (int i = 1; i < path.size(); i++) {
                    if (g[path[i-1]][path[i]] == bottleneck[dst]) {
                        g[path[i-1]][path[i]] = 0;
                        g[path[i]][path[i-1]] = 0;
                    }
                }
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
