#include <bits/stdc++.h>
using namespace std;

int dp[100001][3]; // 합이 i이고 마지막 수가 {1, 2, 3}으로 끝나는 경우의 수
const int MOD = 1e9+9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n;
    cin>>n;

    while(n--)
    {
        int val;
        cin>>val;

        dp[1][0] = 1;
        dp[2][1] = 1;
        dp[3][0] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;

        for(int i = 4; i <= val; ++i)
        {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % MOD;
            dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % MOD;
        }

        int res = (dp[val][0] + ((dp[val][1] + dp[val][2]) % MOD)) % MOD;
        cout<<res<<"\n";
    }
}