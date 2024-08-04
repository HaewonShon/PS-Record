#include <bits/stdc++.h>
using namespace std;

int dp[3][1000][3]; // {시작색, N, 각 색별 cost}
int cost[1000][3];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }

    if(n == 1)
    {
        cout<<min(min(cost[0][0], cost[0][1]), cost[0][2]);
        return 0;
    }

    memset(dp, 0x7f, sizeof(dp)); // 0x7f7f7f7f, 충분히 큰 수로 초기화

    dp[0][0][0] = cost[0][0];
    dp[1][0][1] = cost[0][1];
    dp[2][0][2] = cost[0][2];

    for(int color = 0; color < 3; ++color)
    {   
        for(int i = 1; i < n; ++i)
        {
            dp[color][i][0] = min(dp[color][i-1][1], dp[color][i-1][2]) + cost[i][0];
            dp[color][i][1] = min(dp[color][i-1][0], dp[color][i-1][2]) + cost[i][1];
            dp[color][i][2] = min(dp[color][i-1][0], dp[color][i-1][1]) + cost[i][2];
        }
    }

    int res = 
    min(min(dp[0][n-1][1], dp[0][n-1][2]), min(min(dp[1][n-1][0], dp[1][n-1][2]), min(dp[2][n-1][0], dp[2][n-1][1])));
    cout<<res;
}