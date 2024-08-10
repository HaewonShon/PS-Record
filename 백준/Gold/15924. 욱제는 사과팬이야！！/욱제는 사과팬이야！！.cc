#include <bits/stdc++.h>
using namespace std;

int dp[3000][3000];
const int MOD = 1e9+9;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[n-1][m-1] = 1;

    for(int i = n-1; i >= 0; --i)
    {
        for(int j = m-1; j >= 0; --j)
        {
            if(j > 0 && (board[i][j-1] == 'B' || board[i][j-1] == 'E')) 
                dp[i][j-1] = (dp[i][j-1] + dp[i][j]) % MOD;
            if(i > 0 && (board[i-1][j] == 'B' || board[i-1][j] == 'S'))
                dp[i-1][j] = (dp[i-1][j] + dp[i][j]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    cout<<ans;
}