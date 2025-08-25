#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int i1 = 0;
    int i2 = 0;

    int ans = INT_MAX;
    while(i1 < n)
    {
        if(v[i2] - v[i1] >= m)
        {
            ans = min(ans, v[i2] - v[i1]);
        }

        if(v[i2] - v[i1] < m && i2 < n)
        {
            ++i2;
        }
        else
        {
            ++i1;
        }
    }

    cout<<ans;
}