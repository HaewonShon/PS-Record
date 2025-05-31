#include <bits/stdc++.h>
using namespace std;

int moveCount = 0;

int children[100001][2];

int GetDepthOfEnd(int node)
{
    if(children[node][1] != -1)
    {
        return 1 + GetDepthOfEnd(children[node][1]);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(children, -1, sizeof(children));

    int n;
    cin>>n;


    for(int i = 0; i < n; ++i)
    {
        int parent;
        cin>>parent;

        cin>>children[parent][0]>>children[parent][1];
    }

    int edgeCount = n-1;

    int ans = edgeCount * 2 - GetDepthOfEnd(1);

    cout<<ans;
    
    
}