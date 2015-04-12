#!/usr/bin/env python

def min_heapify(l, i):
    n = len(l)
    j = i+i+1

    while j < n:
        if j+1 < n and l[j] > l[j+1]:
            j += 1

        if l[i] > l[j]:
            l[i], l[j] = l[j], l[i]

        i = j
        j = i+i+1


def build_heap(l):
    n = len(l)
    half = n/2 + 1

    for i in reversed(range(0, half)):
        min_heapify(l, i)



def extract_min(l):
    n = len(l)
    e = l[0]

    l[0] = l[n-1]
    del l[n-1]
    min_heapify(l, 0)
    return e


if __name__ == "__main__":
    l = [1,2,3,4,5,6,7,8,9]
    build_heap(l)

    for i in range(0, len(l)):
        e = extract_min(l)
        print(e)

