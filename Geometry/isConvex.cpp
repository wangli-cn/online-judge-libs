#include <iostream>
#include "geotool.h"

using namespace std;

#define curr(P,i) P[(i) % P.size()]
#define next(P,i) P[(i+1) % P.size()]
#define prev(P,i) P[(i+P.size()-1) % P.size()]

bool isConvex(const Polygon &P)
{
    for (int i = 0; i < P.size(); ++i)
        if (ccw(prev(P, i), curr(P, i), next(P, i)) > 0) return false;
    return true;
}

int main(void)
{
    return 0;
}
