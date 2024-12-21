#include <bits/stdc++.h>
using namespace std;

bool isConnected[100][100];

bool CanConnectEveryone(int p)
{
    vector<bool> visited(p, false);
    visited[0] = true;

    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        int next = q.front();
        q.pop();

        for(int i = 0; i < p; ++i)
        {
            if(isConnected[next][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for(bool isVisited : visited)
    {
        if(!isVisited) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int p, c;
    while(cin>>p>>c)
    {
        if(p == 0 && c == 0) break;

        vector<pair<int, int>> edges(c);
        for(int i = 0; i < c; ++i)
        {
            cin>>edges[i].first>>edges[i].second;
        }

        memset(isConnected, 0, sizeof(isConnected));
        for(auto edge : edges)
        {
            isConnected[edge.first][edge.second] = true;
            isConnected[edge.second][edge.first] = true;
        }

        bool isYes = false;
        for(auto edge : edges)
        {
            isConnected[edge.first][edge.second] = false;
            isConnected[edge.second][edge.first] = false;

            if(!CanConnectEveryone(p))
            {
                isYes = true;
                break;
            }

            isConnected[edge.first][edge.second] = true;
            isConnected[edge.second][edge.first] = true;
        }

        if(isYes) cout<<"Yes\n";
        else cout<<"No\n";
    }


}