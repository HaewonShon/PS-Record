#include <bits/stdc++.h>
using namespace std;

int GetCuttingCost(const vector<vector<pair<int, int>>>& edges,
                    int parent, int current, int parentCuttingCost)
{
    if(parent != -1 && edges[current].size() == 1) return parentCuttingCost; // leaf

    int total = 0;
    for(const pair<int, int>& child : edges[current])
    {
        if(child.first == parent) continue;
        
        total += GetCuttingCost(edges, current, child.first, child.second);
    }

    return min(total, parentCuttingCost);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<pair<int, int>>> edges(n+1);
    for(int i = 0; i < n-1; ++i)
    {
        int a, b, c;
        cin>>a>>b>>c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    cout<<GetCuttingCost(edges, -1, 1, INT_MAX);
}