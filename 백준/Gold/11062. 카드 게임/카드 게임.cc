#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]; // i..j에서 A가 얻을 수 있는 최댓값

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        cin>>n;

        vector<int> v(n);
        vector<int> sum(n, 0);

        cin>>v[0];
        sum[0] = v[0];

        for(int i = 1; i < n; ++i)
        {
            cin>>v[i];
            sum[i] = sum[i-1] + v[i];
        }

        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = v[i];
        }

        for(int len = 1; len < n; ++len)
        {
            for(int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                dp[i][j] = max(v[i] + ((sum[j] - sum[i]) - dp[i+1][j]), // 앞을 먼저 고르는 경우 + 뒤의 최대결과
                    v[j] + ((sum[j-1] - ((i-1 >= 0) ? sum[i-1] : 0)) - dp[i][j-1]));
            }
        }

        cout<<dp[0][n-1]<<"\n";
    }
}