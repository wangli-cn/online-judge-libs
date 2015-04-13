#!/usr/bin/env python

def visit(g, v, order, color):
    color[v] = 1
    for e in g[v]:
        if color[e.dst] == 2:
            continue
        elif color[e.dst] == 1:
            return False
        elif not visit(g, e.dst, order, color):
            return False

    order.append(v)
    color[v] = 2
    return True


def topological_sort(g):
    n = len(g)

    color = [0 * n]
    order = [0 * n]
    for v in range(0, n):
        if color[v] == 0 and not visit(g, v, order, color):
            return False

    return reversed(order)



if __name__ == "__main__":
    pass
