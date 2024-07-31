#include <bits/stdc++.h>
using namespace std;

int GetDepth(vector<int>& parent, int index, int depth)
{
    if(parent[index] < -1) return depth;
    return GetDepth(parent, parent[index], depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> parent(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>parent[i];
        --parent[i];
    }

    for(int i = 0; i < n; ++i)
    {
        if(parent[i] < 0) cout<<0<<"\n";
        else cout<<GetDepth(parent, i, 0)<<"\n";
    }
}