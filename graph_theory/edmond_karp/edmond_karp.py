#!/usr/bin/env python
import numpy
import queue

class Edge():
    def __init__(self, src, dst, weight):
        self.weight = weight
        self.src = src
        self.dst = dst


class Graph():
    def __init__(self, edges):
        self.edges = edges



def edmond_karp(g, s, t):
    n = len(g)

    flow = numpy.zeros((n, n))
    capacity = numpy.zeros((n, n))

    for e in g:
        capacity[e.src, e.dst] += e.weight

    total = 0
    while True:
        Q = queue.Queue(maxsize=n)
        prev = [-1 * n]
        prev[s] = s

        while not Q.empty() and prev[t] < 0:
            u = Q.get()
            for e in g[u]:
                if prev[e.dst] < 0 and (capacity[e.src, e.dst] - flow[e.src, e.dst]) > 0:
                    prev[e.dst] = e.src
                    Q.put(e.dst)

        if prev[t] < 0:
            return total

        inc = 9999999
        j = t
        while prev[j] != j:
            if inc > capacity[prev[j], j] - flow[prev[j], j]:
                inc = capacity[prev[j], j] - flow[prev[j], j]

            j = prev[j]


        j = t
        while prev[j] != j:
            flow[prev[j], j] += inc
            flow[j, prev[j]] -= inc

        total += inc



if __name__ == "__main__":
    pass

