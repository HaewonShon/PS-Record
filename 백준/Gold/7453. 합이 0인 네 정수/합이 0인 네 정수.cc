#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> v(4, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        cin>>v[0][i]>>v[1][i]>>v[2][i]>>v[3][i];
    }

    vector<int> ab;
    vector<int> cd;

    // ab
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ab.push_back(v[0][i] + v[1][j]);
        }
    }

    // cd
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cd.push_back(v[2][i] + v[3][j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long ans = 0;
    
    for(int val : ab)
    {
        auto begin = lower_bound(cd.begin(), cd.end(), -val);
        auto end = upper_bound(cd.begin(), cd.end(), -val);
        ans += end - begin;
    }
    cout<<ans;
}