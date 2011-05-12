#include <iostream>
#include <algorithm>

using namespace std;

int accumulatedDays[500];
int nDaysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool leap(int y) 
{
    return ((y % 4 == 0) && (y % 100 != 0) || (y % 400 ==0));
}

void precompute()
{
    accumulatedDays[0] = 366;
    for (int i = 1; i < 500; ++i)
        accumulatedDays[i] = accumulatedDays[i-1] + 365 + leap(i+1600);
}

int count_days(int year, int month, int day)
{
    int cnt = accumulatedDays[year-1-1600];
    for (int i = 1; i < month; i++)
        cnt += nDaysInMonth[i] + (i == 2 && leap(year));
    cnt += day - 1;
    return cnt;
}

void date(int x)
{
    int yy = 1600, mm = 1, dd = 1;
    for (; x >= 365 + leap(yy); yy++)
        x -= 365 + leap(yy);

    for (; x >= nDaysInMonth[mm] + (mm == 2 && leap(yy)); mm++)
        x -= nDaysInMonth[mm] + (mm == 2 && leap(yy));

    dd += x;
    printf("%02d.%02d.%04d\n", dd, mm, yy);
    return;
}

int main(void)
{
    int n;
    int month, year, day;

    precompute();
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d.%d.%d", &day, &month, &year);
            int t = count_days(year, month, day); //transform to universal representation
            date(t); //transform from universal representation to date format
        }
    }
    return 0;
}
