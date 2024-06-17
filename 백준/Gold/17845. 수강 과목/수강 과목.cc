#include <bits/stdc++.h>
using namespace std;

int dp[1001][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n, k;
    cin>>n>>k;

    for(int i = 1; i <= k; ++i)
    {
        int importance, time;
        cin>>importance>>time;

        for(int j = 0; j < time; ++j)
        {
            dp[i][j] = dp[i-1][j];
        }

        for(int j = time; j <= n; ++j)
        {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-time] + importance);
        }
    }
    
    cout<<dp[k][n];
}