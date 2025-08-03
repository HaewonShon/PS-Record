#include <bits/stdc++.h>
using namespace std;

int dp[1001][501]; // dp[i][j] = i번째 카드 소모 후 j번 마을에 도착했을 때 최대 점수

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0xf7, sizeof(dp));
    int n, m, k;
    cin>>n;

    vector<char> cards(n);
    for(int i = 0; i < n; ++i) cin>>cards[i];

    cin>>m>>k;
    vector<vector<pair<int, char>>> edges(m+1);

    for(int i = 0; i < k; ++i)
    {
        int a, b;
        char c;
        cin>>a>>b>>c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    dp[0][1] = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            for(auto p : edges[j])
            {
                if(p.second == cards[i])
                {
                    dp[i+1][p.first] = max(dp[i+1][p.first], dp[i][j] + 10);
                }
                else
                {
                    dp[i+1][p.first] = max(dp[i+1][p.first], dp[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        ans = max(ans, dp[n][i]);
    }
    cout<<ans;
}