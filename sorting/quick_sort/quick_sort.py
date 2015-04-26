#!/usr/bin/env python

def quick_sort(a, l, r):
    if l < r:
        p = l + (r-l) // 2
        i = l-1
        j = r+1

        while True:
            i += 1
            while a[i] < a[p]:
                i += 1

            j -= 1
            while a[j] > a[p]:
                j -= 1

            if i >= j:
                break

            a[i], a[j] = a[j], a[i]

        quick_sort(a, l, i-1)
        quick_sort(a, j+1, r)



if __name__ == "__main__":
    a = [5,2,3,4,1,7,8]
    quick_sort(a, 0, 6)
    print(a)
