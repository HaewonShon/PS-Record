#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i = 0; i < n/2 + 1; ++i)
    {
        ans += v[i]/2;
    }
    for(int i = n/2+1; i < n; ++i)
    {
        ans += v[i];
    }
    cout<<ans;
}