#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    memset(dp, 0, sizeof(dp));

    vector<int> snacks(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>snacks[i];
    }    

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            if(snacks[j-1] < snacks[i-1])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += snacks[i-1];
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
}