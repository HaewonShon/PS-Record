#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[100000][3][11][2]; // [i][A, B, C 풀이자][A가 푼 수 0~K][C 풀이이 여부]

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n, k;
    cin>>n>>k;

    dp[0][0][1][0] = 1;
    dp[0][1][0][0] = 1;
    dp[0][2][0][1] = 1;

    for(int i = 1; i < n; ++i)
    {
        // A
        dp[i][0][1][0] = ((dp[i-1][0][k][0] + dp[i-1][1][k][0]) % MOD + dp[i-1][1][0][0]) % MOD;
                        
        dp[i][0][1][1] = (((((dp[i-1][0][k][1] + dp[i-1][1][k][1]) % MOD + dp[i-1][2][k][1]) % MOD)
                        + dp[i-1][1][0][1]) % MOD + dp[i-1][2][0][1]) % MOD;

        for(int j = 2; j <= k; ++j)
        {
            dp[i][0][j][0] = (dp[i-1][0][j-1][0] + dp[i-1][1][j-1][0]) % MOD;
            dp[i][0][j][1] = (((dp[i-1][0][j-1][1] + dp[i-1][1][j-1][1]) % MOD) + dp[i-1][2][j-1][1]) % MOD;
        }

        // B
        for(int j = 0; j <= k; ++j)
        {
            dp[i][1][j][0] = dp[i-1][0][j][0];
            dp[i][1][j][1] = (dp[i-1][0][j][1] + dp[i-1][2][j][1]) % MOD;
        }

        for(int j = 0; j <= k; ++j)
        {
            dp[i][2][j][1] += dp[i-1][0][j][0];
            dp[i][2][j][1] %= MOD;

            dp[i][2][j][1] += dp[i-1][1][j][0];
            dp[i][2][j][1] %= MOD;

            dp[i][2][j][1] += dp[i-1][2][j][0];
            dp[i][2][j][1] %= MOD;

            dp[i][2][j][1] += dp[i-1][0][j][1];
            dp[i][2][j][1] %= MOD;

            dp[i][2][j][1] += dp[i-1][1][j][1];
            dp[i][2][j][1] %= MOD;

            dp[i][2][j][1] += dp[i-1][2][j][1];
            dp[i][2][j][1] %= MOD;
        }
    }

    int ans = 0;

    ans += dp[n-1][0][0][1];
    ans += dp[n-1][1][0][1];
    ans %= MOD;
    ans += dp[n-1][2][0][1];
    ans %= MOD;

    if(k >= 1)
    {
        ans += dp[n-1][0][k][1];
        ans %= MOD;
        ans += dp[n-1][1][k][1];
        ans %= MOD;
        ans += dp[n-1][2][k][1];
        ans %= MOD;
    }
    cout<<ans;
}