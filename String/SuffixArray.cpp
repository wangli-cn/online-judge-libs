#include <iostream>

using namespace std;

const int MAXN = 10000;

char s[2*MAXN];
int m[4][2*MAXN];

void createSuffixArray(unsigned char *text, int L, int **_S, int **_R, int **_T1, int **_T2)
{
    int i, h, h2;
    int *SA_h = *_S;
    int *SA_2h = *_T1;
    int *Rank = *_R;
    int *bucket = *_T2; //bucket to mark the bottom of each bucket
    int *tmp;

    //Radix Sort by one character
    for (i = 0; i < 256; ++i)
        bucket[i] = 0;
    for (i = 0; i < L; ++i)
        bucket[text[i]]++;
    for (i = 1; i < 256; ++i)
        bucket[i] += bucket[i-1];
    for (i = 0; i < L; ++i)
        SA_h[--bucket[text[i]]] = i;

    //compute rank. where h = 1, the rank start from 0
    Rank[SA_h[0]] = 0;
    for (i = 1; i < L; ++i) {
        if (text[SA_h[i]] == text[SA_h[i-1]])
            Rank[SA_h[i]] = Rank[SA_h[i-1]];
        else 
            Rank[SA_h[i]] = Rank[SA_h[i-1]] + 1;
    }

    //Doubling Algorithm
    //SA(h) => Rank(h) => SA(2h) => Rank(2h) => ...
    for (h = 1; h < L && Rank[SA_h[L-1]] < L-1; h <<= 1) {
        //Of the same rank in SA(h), bucket bottom is at the max i
        for (i = 0; i < L; ++i)
            bucket[Rank[SA_h[i]]] = i;

        //compute SA(2h)
        //All of the suffixes in the same bucket must have the same h-prefix
        //so we only need to compare h+1 ~ 2h for 2h-prefix
        //but h+1 ~ 2h is the h-prefix of some other suffix
        //we traverse the SA(h) reversely
        //so we put the SA_h[i] - h to the bucket bottom
        for (i = L-1; i >= 0; --i)
            if (h <= SA_h[i])
                SA_2h[bucket[Rank[SA_h[i]-h]]--] = SA_h[i] - h;

        //for the suffixed whose length less than h
        //they are actually in the seperate bucket
        //so we only have to copy them to SA(2h)
        for (i = L-h, h2 = L-(h>>1); i < h2; ++i)
            SA_2h[bucket[Rank[i]]] = i;

        tmp = SA_h; SA_h = SA_2h; SA_2h = tmp;

        //compute Rank(2h)
        //To determine wether we need to put into different bucket
        //we check the first half and second half of 2h-prefix
        bucket[SA_h[0]] = 0;
        for (i = 1; i < L; ++i) {
            //we don't have to worry about SA_h[i] + h will be greater than L
            //before that the first condition will not be satisfied
            if (Rank[SA_h[i]] != Rank[SA_h[i-1]] || Rank[SA_h[i]+h] != Rank[SA_h[i-1] + h])
                bucket[SA_h[i]] = bucket[SA_h[i-1]] + 1;
            else 
                bucket[SA_h[i]] = bucket[SA_h[i-1]];
        }

        tmp = bucket; bucket = Rank; Rank = tmp;
    }

    if (*_S != SA_h)
        *_S = SA_h, *_T1 = SA_2h;
    if (*_R != Rank)
        *_R = Rank, *_T2 = bucket;
}

void computeHeight(unsigned char *text, int L, int *SA, int *Rank, int *Height, int *tmp)
{
    int i, j, k;

    //k denotes h[i] here
    for (k = 0, i = 0; i < L; ++i) {
        //the rank start from 0, so if rank[i] == 0, Height[i] = 0;
        if (Rank[i] == 0)
            Height[Rank[i]] = 0;
        else {
            for (j = SA[Rank[i]-1]; text[i+k] == text[j+k]; k++);

            //h[i] = Height[Rank[i]]
            Height[Rank[i]] = k;

            //h[i]-1
            if (k > 0) k--;
        }
    }
}

int main(void)
{
    return 0;
}
