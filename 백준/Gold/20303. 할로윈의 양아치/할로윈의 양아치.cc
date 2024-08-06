#include <bits/stdc++.h>
using namespace std;

int dp[30001][3001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<int> candies(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin>>candies[i];
    }

    vector<vector<int>> edges(n+1);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<pair<int, int>> groups; // 각 아이들 그룹별 인원수 및 사탕의 합

    // 각 그룹별 사탕 합 계산
    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            int groupTotal = candies[i];
            int groupMembers = 1;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int child = q.front();
                q.pop();

                for(int next : edges[child])
                {
                    if(!visited[next])
                    {
                        groupTotal += candies[next];
                        visited[next] = true;
                        ++groupMembers;
                        q.push(next);
                    }
                }
            }

            groups.push_back({groupMembers, groupTotal});
        }
    }

    // knapsack
    memset(dp, 0, sizeof(dp));
    int groupSize = groups.size();

    for(int i = 1; i <= groupSize; ++i)
    {
        int j = 1;
        for(; j < groups[i-1].first; ++j)
        {
            dp[i][j] = dp[i-1][j];
        }
        for(; j < k; ++j)
        {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-groups[i-1].first] + groups[i-1].second);
        }
    }

    cout<<dp[groupSize][k-1];
    
}