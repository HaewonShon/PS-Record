#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
pair<int, int> dp[1000][1000]; // {res, expected}

int main()
{
    ios_base::sync_with_stdio(false); 
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
    
    if(board[0][0] == 0) dp[0][0] = {1, 1};
    else dp[0][0] = {0, 0};

    for(int i = 1; i < n; ++i)
    {
        if(board[0][i] == dp[0][i-1].second)
        {
            dp[0][i] = {dp[0][i-1].first + 1, (dp[0][i-1].second + 1) % 3};
        }
        else
        {
            dp[0][i] = dp[0][i-1];
        }

        if(board[i][0] == dp[i-1][0].second)
        {
            dp[i][0] = {dp[i-1][0].first + 1, (dp[i-1][0].second + 1) % 3};
        }
        else
        {
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            // from top
            if(dp[i-1][j].second == board[i][j])
            {
                dp[i][j] = {dp[i-1][j].first + 1, (board[i][j] + 1) % 3};
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }

            // from left
            if(dp[i][j-1].first < dp[i][j].first) continue;

            if(dp[i][j-1].second == board[i][j])
            {
                dp[i][j] = {dp[i][j-1].first + 1, (board[i][j] + 1) % 3};
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout<<dp[n-1][n-1].first;
}