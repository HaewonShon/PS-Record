#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin>>n>>k>>m;

    vector<vector<int>> station(n+1);
    vector<vector<int>> hypertube(m, vector<int>(k));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            cin>>hypertube[i][j];
            station[hypertube[i][j]].push_back(i);
        }
    }

    vector<int> dist(n+1, -1);
    dist[1] = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int s = q.front();
        q.pop();

        if(s == n)
        {
            cout<<dist[n];
            return 0;
        }

        for(int ht : station[s])
        {
            for(int nextS : hypertube[ht])
            {
                if(dist[nextS] == -1)
                {
                    dist[nextS] = dist[s] + 1;
                    q.push(nextS);
                }
            }
        }
    }

    cout<<-1;
}