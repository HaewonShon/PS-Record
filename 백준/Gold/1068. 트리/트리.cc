#include <bits/stdc++.h>
using namespace std;

int CountLeaves(int node, int removed, const vector<vector<int>>& children)
{
    if(node == removed) return 0;
    if(children[node].size() == 0) return 1;

    int res = 0;
    for(int child : children[node])
    {
        res += CountLeaves(child, removed, children);
    }
    if(res == 0) return 1; // 본인이 leaf
    else return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> children(n);
    vector<int> parent(n);

    int root = -1;

    for(int i = 0; i < n; ++i)
    {
        cin>>parent[i];

        if(parent[i] != -1)
        {
            children[parent[i]].push_back(i);
        }
        else
        {
            root = i;
        }
    }

    int removed;
    cin>>removed;

    cout<<CountLeaves(root, removed, children);
}