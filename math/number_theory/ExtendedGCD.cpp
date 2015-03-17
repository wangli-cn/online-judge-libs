int extended_gcd(int a, int b, int &x, int &y)
{
    int d;
    if (!b) { x = 1; y = 0; return a; }
    else { 
        d = extended_gcd(b, a%b, y, x); 
        y -= (a/b) * x;
        return d;
    }
}
