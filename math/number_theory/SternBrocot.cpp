#include <iostream>

using namespace std;

//Stern-Brocot Tree for enumerating rationals
void sternBrocot(int B, int pl = 0, int ql = 1, int pr = 1, int qr = 0)
{
    int pm = pl + pr, qm = ql + qr;
    if (pm + qm > B) return;
    sternBrocot(B, pl, ql, pm, qm);
    cout << pm << "/" << qm << endl;
    sternBrocot(B, pm, qm, pr, qr);
}

int main(void)
{
    return 0;
}
