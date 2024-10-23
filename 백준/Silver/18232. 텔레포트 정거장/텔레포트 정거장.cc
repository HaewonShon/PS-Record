#include <bits/stdc++.h>
using namespace std;

vector<int> tp[300001];
int dist[300001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, s, e;
    cin>>n>>m>>s>>e;

    if(m == 0)
    {
        cout<<abs(s-e);
        return 0;
    }

    memset(dist, -1, sizeof(dist));

    while(m--)
    {
        int x, y;
        cin>>x>>y;

        tp[x].push_back(y);
        tp[y].push_back(x);
    }

    // BFS
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(curr == e)
        {
            cout<<dist[curr];
            return 0;
        }

        if(curr > 1 && dist[curr-1] == -1)
        {
            q.push(curr-1);
            dist[curr-1] = dist[curr] + 1;
        }

        if(curr < n && dist[curr+1] == -1)
        {
            q.push(curr+1);
            dist[curr+1] = dist[curr] + 1;
        }

        for(int connected : tp[curr])
        {
            if(dist[connected] == -1)
            {
                q.push(connected);
                dist[connected] = dist[curr] + 1;
            }
        }
    }
}