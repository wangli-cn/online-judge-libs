#ifndef __GRAPH
#define __GRAPH

#include <vector>
#include <limits>
#include "utils/common.h"

using Weight = int;

class Edge
{
public:
    int src, dst;
    Weight weight;

    Edge() = delete;
    explicit Edge(int src, int dst, Weight weight = 0)
        :src(src), dst(dst), weight(weight) {}
};

using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

bool operator<(const Edge &e, const Edge &f)
{
    return (e.weight != f.weight) ? e.weight > f.weight :
           (e.src != f.src) ? e.src > f.src : e.dst > f.dst;
}

#endif
