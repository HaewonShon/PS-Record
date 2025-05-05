#include <bits/stdc++.h>
using namespace std;

int dp[1000001][2];

int DFS(int node, int parent, bool isEarlyAdapter, vector<vector<int>>& edges)
{
    if(dp[node][isEarlyAdapter] != -1) return dp[node][isEarlyAdapter];

    int res = isEarlyAdapter ? 1 : 0;

    for(int child : edges[node])
    {
        if(child == parent) continue;

        int childEarlyAdapter = DFS(child, node, true, edges);
        int childNotEarlyAdapter = DFS(child, node, false, edges);

        if(isEarlyAdapter)
        {
            res += min(childEarlyAdapter, childNotEarlyAdapter);
        }
        else
        {
            res += childEarlyAdapter;
        }
    }

    dp[node][isEarlyAdapter] = res;
    return res;    
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int n;
    cin>>n;

    vector<vector<int>> edges(n+1);

    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin>>a>>b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int ans = DFS(1, -1, true, edges);
    ans = min(ans, DFS(1, -1, false, edges));

    cout<<ans;
}