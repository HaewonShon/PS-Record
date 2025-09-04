#include <bits/stdc++.h>
using namespace std;

int board[3000][3000];
int dp[3000][3000];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>board[i][j];
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i < n; ++i)
    {
        dp[i][0] = dp[i-1][0] + max(0, board[i][0] - board[i-1][0] + 1);
    }
    for(int j = 1; j < n; ++j)
    {
        dp[0][j] = dp[0][j-1] + max(0, board[0][j] - board[0][j-1] + 1);
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            dp[i][j] = min(dp[i-1][j] + max(0, board[i][j] - board[i-1][j] + 1),
                            dp[i][j-1] + max(0, board[i][j] - board[i][j-1] + 1));
        }
    }

    cout<<dp[n-1][n-1];
}