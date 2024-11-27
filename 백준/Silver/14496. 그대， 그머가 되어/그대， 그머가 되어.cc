#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;

    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges(n+1);
    vector<int> visit(n+1, INT_MAX);

    while(m--)
    {
        int c1, c2;
        cin>>c1>>c2;
        edges[c1].push_back(c2);
        edges[c2].push_back(c1);
    }

    queue<int> q;
    q.push(a);
    visit[a] = 0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(curr == b)
        {
            cout<<visit[curr];
            return 0;
        }

        for(int next : edges[curr])
        {
            if(visit[next] == INT_MAX)
            {
                visit[next] = visit[curr] + 1;
                q.push(next);
            }
        }
    }

    cout<<-1;
}