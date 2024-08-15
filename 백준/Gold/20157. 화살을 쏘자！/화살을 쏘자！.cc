#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    map<pair<int, int>, int> m;

    while(n--)
    {
        int x, y;
        cin>>x>>y;
        int divisor = gcd(max(abs(x), abs(y)), min(abs(x), abs(y)));
        ++m[{x/divisor, y/divisor}];
    }

    int ans = 0;
    for(auto p : m)
    {
        ans = max(ans, p.second);
    }
    cout<<ans;
}