#include <bits/stdc++.h>
using namespace std;

int dp[10][10][8]; // index별 경우의 수
const string target = "YOKOHAMA";

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    memset(dp, 0, sizeof(dp));

    vector<string> board(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>board[i];
    }

    for(int index = 0; index < 8; ++index)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(board[i][j] == target[index])
                {
                    if(index == 0) dp[i][j][index] = 1;
                    else
                    {
                        if(i > 0 && board[i-1][j] == target[index-1]) dp[i][j][index] += dp[i-1][j][index-1];
                        if(i < n-1 && board[i+1][j] == target[index-1]) dp[i][j][index] += dp[i+1][j][index-1];
                        if(j > 0 && board[i][j-1] == target[index-1]) dp[i][j][index] += dp[i][j-1][index-1];
                        if(j < m-1 && board[i][j+1] == target[index-1]) dp[i][j][index] += dp[i][j+1][index-1];
                    }
                }
            }       
        }
    }

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ans += dp[i][j][7];
        }
    }
    cout<<ans;
}
