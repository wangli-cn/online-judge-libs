#!/usr/bin/env python


def is_greater(s1, s2):
    if len(s1) != len(s2):
        return len(s1) > len(s2)

    for i in range(0, len(s1)):
        if s1[i] != s2[i]:
            return ord(s1[i]) > ord(s2[i])

    return False


def increment(s, pos1, pos2):
    if pos1 < 0 or pos2 >= len(s):
        s = '1' + s + '1'
    elif int(s[pos1]) < 9:
        if pos1 == pos2:
            t1 = chr(ord(s[pos1])+1)
            s = s[0 : pos1] + t1 + s[pos1+1 : ]
        else:
            t1 = chr(ord(s[pos1])+1)
            t2 = chr(ord(s[pos2])+1)
            s = s[0 : pos1] + t2 + s[pos1+1 : pos2] + t1 + s[pos2+1: ]
    else:
        if pos1 == pos2:
            s = s[0 : pos1] + '0' + s[pos1+1 : ]
            s = increment(s, pos1-1, pos1+1)
        else:
            if pos1+1 == pos2:
                s = s[0 : pos1] + '00' + s[pos2+1: ]
                s = increment(s, pos1-1, pos2+1)
            else:
                s = s[0 : pos1] + '0' + s[pos1+1 : pos2] + '0' + s[pos2+1: ]
                s = increment(s, pos1-1, pos2+1)

    return s


def next_palindrome(s):
    n = len(s)

    if n % 2 == 0:
        half = n // 2
        first_half = s[0 : half]
        second_half = first_half[::-1]

        ss = first_half + second_half
        if is_greater(ss, s):
            s = ss
        else:
            s = increment(ss, half-1, half)
    else:
        half = n // 2
        middle = s[half]
        first_half = s[0 : half]
        second_half = first_half[::-1]

        ss = first_half + middle + second_half
        if is_greater(ss, s):
            s = ss
        else:
            s = increment(ss, half, half)

    print(s)


if __name__ == "__main__":
    n_case = int(input())
    for i in range(0, n_case):
        s = input()
        next_palindrome(s)
