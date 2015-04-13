#!/usr/bin/env python

def netty_binary_search(a, v):
    l = -1
    r = len(a)

    while (l+1 != r):
        m = l + (r-l)/2

        if v < a[m]:
            r = m
        else:
            l = m

    if l > -1:
        return l
    else:
        return -1


def bently_binary_search(a, v):
    l = 0
    r = len(a)-1

    while (l < r):
        m = l + (r-l)/2

        if v <= a[m]:
            r = m
        else:
            l = m+1

    if a[l] == v:
        return l
    else:
        return -1


if __name__ == '__main__':
    a = [1,2,3,4,5,6,7,8,9]
    print(bently_binary_search(a, 1))
    print(netty_binary_search(a, 1))
