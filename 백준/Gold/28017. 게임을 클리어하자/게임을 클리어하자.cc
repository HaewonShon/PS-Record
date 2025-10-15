#include <bits/stdc++.h>
using namespace std;

int dp[501][501]; // i회차, j무기 최솟값

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x7F, sizeof(dp));
    
    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i < m; ++i)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int clearTime;
            cin>>clearTime;

            for(int k = 0; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][k]);
            }
            for(int k = j + 1; k < m; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][k]);
            }

            dp[i][j] += clearTime;
        }
    }

    int ans = INT_MAX;    
    for(int i = 0; i < m; ++i)
    {
        ans = min(ans, dp[n][i]);
    }
    cout<<ans;
}   