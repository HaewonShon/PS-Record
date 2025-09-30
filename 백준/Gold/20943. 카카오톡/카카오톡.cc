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

    long long n;
    cin>>n;

    map<pair<int, int>, long long> m;
    for(int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin>>a>>b>>c;

        if(a < 0 && b < 0)
        {
            a = -a;
            b = -b;
        }
        else if(a < 0)
        {
            a = -a;
            b = -b;
        }

        if(a == 0) m[{0, 1}]++;
        else if(b == 0) m[{1, 0}]++;
        else
        {
            int divisor = gcd(abs(a), abs(b));
            m[{a / divisor, b / divisor}]++;
        }
    }

    long long res = 0;

    for(auto p : m)
    {
        res += p.second * (n - p.second);
    }
    cout<<res / 2;
}