#include <bits/stdc++.h>
using namespace std;

int DFS(vector<vector<pair<int, int>>>& edges, int start, int from, int cost, const int k)
{
    int res = 0;
    if(cost >= k) ++res;

    for(auto p : edges[start])
    {
        if(p.first == from) continue;

        res += DFS(edges, p.first, start, min(cost, p.second), k);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, Q;
    cin>>N>>Q;  

    vector<vector<pair<int, int>>> edges(N+1);
    for(int i = 0; i < N-1; ++i)
    {
        int p, q, r;
        cin>>p>>q>>r;
        edges[p].push_back({q, r});
        edges[q].push_back({p, r});
    }

    while(Q--)
    {
        int k, v;
        cin>>k>>v;

        cout<<DFS(edges, v, -1, INT_MAX, k) - 1<<"\n"; // 자신 제외
    }
}