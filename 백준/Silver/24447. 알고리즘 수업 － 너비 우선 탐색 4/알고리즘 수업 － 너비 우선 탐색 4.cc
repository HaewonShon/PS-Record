#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, r;
    cin>>n>>m>>r;

    vector<vector<int>> edges(n+1);

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin>>a>>b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(vector<int>& v : edges)
    {
        sort(v.begin(), v.end()); // 정점을 오름차순으로 방문하기 위함
    }

    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(r);
    visited[r] = true;

    long long depth = 0;
    long long order = 1;

    long long ans = 0;

    while(!q.empty())
    {
        int queueSize = q.size();
        for(int i = 0; i < queueSize; ++i)
        {
            int curr = q.front();
            q.pop();
            
            ans += depth * order++;

            for(int next : edges[curr])
            {
                if(!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        ++depth;
    }
    cout<<ans;
}