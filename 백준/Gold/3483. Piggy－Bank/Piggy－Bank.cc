#include <bits/stdc++.h>
using namespace std;

int dp[501][10001]; // i번째 동전까지 진행했을 때 무게가 j일 때 최솟값

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int e, f;
        cin>>e>>f;

        int totalWeight = f - e; // 전체 - 저금통 무게

        int n;
        cin>>n;

        vector<pair<int, int>> coins(n); // {무게, 가격}
        for(int i = 0; i < n; ++i)
        {
            cin>>coins[i].first>>coins[i].second;
        }

        memset(dp, 0x7f, sizeof(dp)); // 큰 수 초기화

        for(int i = 1; i <= n; ++i)
        {
            int weight = coins[i-1].second;
            int value = coins[i-1].first;

            for(int j = 1; j <= weight; ++j)
            {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][weight] = min(dp[i][weight], value);
            for(int j = weight + 1; j <= totalWeight; ++j)
            {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = min(dp[i][j], value + min(dp[i-1][j-weight], dp[i][j-weight]));
            }
        }

        int ans = dp[n][totalWeight];        
        if(ans == 0x7f7f7f7f)
        {
            cout<<"This is impossible.\n";
        }
        else
        {
            cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
        }

    }
}