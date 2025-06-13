#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> interval;
    vector<vector<int>> edges;

    interval.push_back({-1, -1});
    edges.push_back({});

    while(n--)
    {
        int cmd;
        cin>>cmd;

        if(cmd == 1)
        {
            int a, b;
            cin>>a>>b;
            interval.push_back({a, b});
            edges.push_back({});

            for(int i = 1; i < interval.size(); ++i)
            {
                for(int j = i + 1; j < interval.size(); ++j)
                {
                    if(i == j) continue;

                    if((interval[i].first > interval[j].first && interval[i].first < interval[j].second)
                        || (interval[i].second > interval[j].first && interval[i].second < interval[j].second))
                    {
                        edges[i].push_back(j);
                    }

                    if((interval[j].first > interval[i].first && interval[j].first < interval[i].second)
                        || (interval[j].second > interval[i].first && interval[j].second < interval[i].second))
                    {
                        edges[j].push_back(i);
                    }
                }
            }

        }
        else if(cmd == 2)
        {
            int a, b;
            cin>>a>>b;

            queue<int> q;
            vector<bool> visited(interval.size(), false);
            q.push(a);
            visited[a] = true;

            while(!q.empty())
            {
                int next = q.front();
                q.pop();

                if(next == b) break;

                for(int neighbor : edges[next])
                {
                    if(!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            cout<<visited[b]<<"\n";


        }
    }
}