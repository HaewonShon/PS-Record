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

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin>>v[i];

        if(n == 1)
        {
            cout<<v[0]<<"\n";
            continue;
        }

        sort(v.begin(), v.end());

        if(v.front() == v.back())
        {
            cout<<"INFINITY\n";
            continue;
        }

        int ans = v[1] - v[0];

        for(int i = 2; i < n; ++i)
        {
            ans = gcd(max(ans, v[i] - v[i-1]), min(ans, v[i] - v[i-1]));
        }

        cout<<ans<<"\n";
    }
}