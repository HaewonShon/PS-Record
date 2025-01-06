#include <bits/stdc++.h>
using namespace std;

int nodes[100001];

void FillMiniMax(const vector<vector<int>>& edges, int node, int parent, bool isMax)
{
    if(isMax)
    {
        nodes[node] = 0;

        for(int child : edges[node])
        {
            if(child == parent) continue;

            if(nodes[child] == -1)
            {
                FillMiniMax(edges, child, node, !isMax);
            }
            nodes[node] = max(nodes[node], nodes[child]);
        }
    }
    else
    {
        nodes[node] = INT_MAX;

        for(int child : edges[node])
        {
            if(child == parent) continue;

            if(nodes[child] == -1)
            {
                FillMiniMax(edges, child, node, !isMax);
            }
            nodes[node] = min(nodes[node], nodes[child]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(nodes, -1, sizeof(nodes));

    int n, r;
    cin>>n>>r;

    vector<vector<int>> edges(n+1);

    for(int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin>>u>>v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int l;
    cin>>l;

    for(int i = 0; i < l; ++i)
    {
        int k, t;
        cin>>k>>t;

        nodes[k] = t;
    }

    FillMiniMax(edges, r, -1, true);

    int q;
    cin>>q;

    for(int i = 0; i < q; ++i)
    {
        int request;
        cin>>request;

        cout<<nodes[request]<<"\n";
    }
}