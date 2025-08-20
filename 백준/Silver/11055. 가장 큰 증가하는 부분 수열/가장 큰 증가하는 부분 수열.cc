#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n;
    cin>>n;

    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; ++i) cin>>v[i];

    for(int i = 1; i <= n; ++i)
    {
        int best = 0;
        for(int j = 1; j < i; ++j)
        {
            if(v[i] > v[j] && dp[j] > dp[best]) best = j;
        }

        dp[i] = dp[best] + v[i];
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
}