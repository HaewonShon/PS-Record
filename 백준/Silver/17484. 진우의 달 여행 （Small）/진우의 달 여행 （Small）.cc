    #include <bits/stdc++.h>
    using namespace std;

    int dp[1001][1000][3]; // 왼위, 중앙, 오위

    int main()
    { 
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        memset(dp, 0, sizeof(dp));

        int n, m;
        cin>>n>>m;

        vector<vector<int>> board(n + 1, vector<int>(m));

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                cin>>board[i][j];
            }
        }

        dp[0][0][0] = INT_MAX;
        dp[0][m-1][2] = INT_MAX;

        for(int i = 1; i <= n; ++i)
        {
            // 왼쪽 끝
            dp[i][0][0] = INT_MAX;
            dp[i][0][1] = dp[i-1][0][2] + board[i][0];
            dp[i][0][2] = min(dp[i-1][1][0], dp[i-1][1][1]) + board[i][0];

            // 중앙
            for(int j = 1; j < m-1; ++j)
            {
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + board[i][j];
                dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + board[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + board[i][j];
            }

            // 오른쪽 끝
            dp[i][m-1][0] = min(dp[i-1][m-2][1], dp[i-1][m-2][2]) + board[i][m-1];
            dp[i][m-1][1] = dp[i-1][m-1][0] + board[i][m-1];
            dp[i][m-1][2] = INT_MAX;
        }

        int ans = INT_MAX;
        for(int i = 0; i < m; ++i)
        {
            for(int k = 0; k < 3; ++k)
            {
                ans = min(ans, dp[n][i][k]);
            }
        }
        cout<<ans;
    }