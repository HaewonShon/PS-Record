#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, d2, m1, m2, y1, y2, n;
    cin>>d1>>m1>>y1>>n;
    cin>>d2>>m2>>y2;

    d2 -= d1;
    if(d2 < 0)
    {
        d2 += 30;
        m2 -= 1;
    }

    m2 -= m1;
    if(m2 < 0)
    {
        m2 += 12;
        y2 -= 1;
    }
    y2 -= y1;

    int diff = d2 + m2 * 30 + y2 * 360;
    n -= 1;
    n += diff;
    n %= 7;
    n += 1;
    cout<<n;
}