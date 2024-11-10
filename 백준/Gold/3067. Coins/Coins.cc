#include <bits/stdc++.h>
using namespace std;

int dp[21][10001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n;

        vector<int> coins(n+1);
        for(int i = 1; i <= n; ++i) cin>>coins[i];

        cin>>m;

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i)
        {
            int coin = coins[i];
            for(int j = 0; j <= m; ++j)
            {
                dp[i][j] = dp[i-1][j];
            }


            while(coin <= m)
            {
                for(int j = coin; j <= m; ++j)
                {
                    dp[i][j] += dp[i-1][j-coin];
                }

                coin += coins[i];
            }
        }

        cout<<dp[n][m]<<"\n";
    }
}