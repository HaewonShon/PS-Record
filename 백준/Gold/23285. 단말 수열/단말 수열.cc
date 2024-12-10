#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> input(n-2);
    vector<int> leftChildren(n+1, 0);
    for(int i = 0; i < n-2; ++i)
    {
        cin>>input[i];
        ++leftChildren[input[i]];
    } 

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; ++i)
    {
        if(leftChildren[i] == 0) pq.push(i);
    }

    vector<vector<int>> ans(n+1);
    for(int i = 0; i < n-2; ++i)
    {
        int child = pq.top();
        pq.pop();

        ans[min(input[i], child)].push_back(max(input[i], child));
        if(--leftChildren[input[i]] == 0)
        {
            pq.push(input[i]);
        }
    }

    // last edge
    int v1 = pq.top();
    pq.pop();
    int v2 = pq.top();
    ans[min(v1, v2)].push_back(max(v1, v2));

    for(int i = 1; i <= n; ++i)
    {
        sort(ans[i].begin(), ans[i].end());
        for(int child : ans[i])
        {
            cout<<i<<" "<<child<<"\n";
        }
    }
}
