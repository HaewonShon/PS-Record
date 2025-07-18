#include <bits/stdc++.h>
using namespace std;

int dp[100001];
const int MOD = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n, h;
    cin>>n>>h;

    vector<int> cup(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>cup[i];
        ++dp[cup[i]];
    }

    for(int height = 1; height <= h; ++height)
    {
        for(int cupHeight : cup)
        {
            if(height - cupHeight > 0)
            {
                dp[height] += dp[height - cupHeight];
                dp[height] %= MOD;
            }
        }
    }

    cout<<dp[h];
}