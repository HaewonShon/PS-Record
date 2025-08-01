#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int>& v, int n, int m, int startIndex, int curr, int& res)
{
    if(m == 0)
    {
        res = max(curr, res);
        return;
    }

    for(int i = startIndex; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            DFS(v, n, m-1, j, curr + v[j] - v[i], res);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin>>v[i];
        v[i] += v[i-1];
    }

    int res = -1e9;
    DFS(v, n, m, 0, 0, res);
    cout<<res;
}