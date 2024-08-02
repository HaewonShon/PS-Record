#include <bits/stdc++.h>
using namespace std;

int dp[101][101]; // {day, coupon}d

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    memset(dp, -1, sizeof(dp));

    vector<bool> availableDays(n+1, true);
    for(int i = 0; i < m; ++i)
    {
        int workDay;
        cin>>workDay;
        availableDays[workDay] = false;
    }

    dp[0][0] = 0;

    for(int i = 0; i < n; ++i)
    {
        if(availableDays[i+1] == false)
        {
            for(int j = 0; j <= 100; ++j)
            {
                if(dp[i][j] != -1)
                {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        else
        {
            for(int j = 0; j <= 100; ++j) // 쿠폰 사용 가능한경우
            {
                if(j >= 3 && dp[i][j] != -1)
                {
                    if(dp[i+1][j-3] == -1) dp[i+1][j-3] = INT_MAX;
                    dp[i+1][j-3] = min(dp[i+1][j-3], dp[i][j]);
                }
            }

            for(int j = 0; j <= 100; ++j) // 쿠폰 사용 가능한경우
            {
                if(dp[i][j] != -1)
                {
                    if(dp[i+1][j] == -1) dp[i+1][j] = INT_MAX;
                    if(dp[min(i+3, n)][j+1] == -1) dp[min(i+3, n)][j+1] = INT_MAX;
                    if(dp[min(i+5, n)][j+2] == -1) dp[min(i+5, n)][j+2] = INT_MAX;

                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 10000);
                    dp[min(i+3, n)][j+1] = min(dp[min(i+3, n)][j+1], dp[i][j] + 25000);
                    dp[min(i+5, n)][j+2] = min(dp[min(i+5, n)][j+2], dp[i][j] + 37000);
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i <= 100; ++i)
    {
        if(dp[n][i] == -1) continue;
        ans = min(ans, dp[n][i]);
    }
    cout<<ans;
}