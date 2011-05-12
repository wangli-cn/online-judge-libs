int joseph_problem(int N, int M)
{
    int i = 0;
    for (int k = 1; k <= N; ++k) 
        i = (i+M) % k;
    return i;
}
