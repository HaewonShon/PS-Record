#include <bits/stdc++.h>
using namespace std;

int dp[300001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x7f, sizeof(dp));

    dp[0] = 0;

    int n;
    cin>>n;

    vector<int> v(200);
    v[0] = 1;
    for(int i = 1; i < 200; ++i)
    {
        v[i] = v[i-1] + (i + 1) * (i + 2) / 2;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < 200; ++j)
        {
            if(v[j] > i) break;
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }
    cout<<dp[n];
}   