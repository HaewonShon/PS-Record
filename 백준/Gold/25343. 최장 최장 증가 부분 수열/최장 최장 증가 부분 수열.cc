#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>v[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            dp[i+1][j+1] = 1;
            for(int _i = 0; _i <= i; ++_i)
            {
                for(int _j = 0; _j <= j; ++_j)
                {
                    if(v[i][j] > v[_i][_j])
                    {
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[_i+1][_j+1] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
}