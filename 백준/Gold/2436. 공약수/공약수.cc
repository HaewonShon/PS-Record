#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin>>A>>B;

    if(B % A != 0)
    {
        return 0;
    }
    
    int xy = B/A;
    int maxX = sqrt(xy);

    int ansX, ansY;

    for(int x = 1; x <= maxX; ++x)
    {
        if(xy % x == 0 && gcd(xy / x, x) == 1)
        {
            ansX = x;
            ansY = xy / x;
        }
    }
    
    cout<<A * ansX<<" "<<A * ansY;
}