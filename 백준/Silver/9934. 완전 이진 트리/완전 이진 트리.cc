#include <bits/stdc++.h>
using namespace std;

void Visit(vector<vector<int>>& nodes, int level, int k)
{
    if(level == k) return;

    Visit(nodes, level + 1, k);

    int val;
    cin>>val;
    nodes[level].push_back(val);

    Visit(nodes, level + 1, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;

    vector<vector<int>> nodes(k);
    Visit(nodes, 0, k);

    for(int i = 0; i < k; ++i)
    {
        for(int node : nodes[i])
        {
            cout<<node<<" ";
        }
        cout<<"\n";
    }
}