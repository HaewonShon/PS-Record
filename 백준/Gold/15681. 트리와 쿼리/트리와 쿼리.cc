#include <bits/stdc++.h>
using namespace std;

int GetChildNum(vector<int>& childNum, vector<vector<int>>& edges, int index)
{
    if(childNum[index] != -1) return 0;

    childNum[index] = 0;
    for(int neighbor : edges[index])
    {
        childNum[index] += GetChildNum(childNum, edges, neighbor);
    }
    return childNum[index] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, r, q;
    cin>>n>>r>>q;

    vector<vector<int>> edges(n+1);

    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> childNum(n+1, -1);
    GetChildNum(childNum, edges, r);

    while(q--)
    {
        int index;
        cin>>index;
        cout<<childNum[index] + 1<<"\n";
    }
}