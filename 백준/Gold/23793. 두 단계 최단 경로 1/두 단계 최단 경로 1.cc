#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> edges(n+1);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edges[a].push_back({b, c});
    }

    int x, y, z;
    cin>>x>>y>>z;

    // y를 거치는 경우
    // x->y
    vector<int> cost(n+1, INT_MAX);
    priority_queue<pair<int, int>> q;

    cost[x] = 0;
    q.push({0, x});

    while(!q.empty())
    {
        auto p = q.top();
        q.pop();

        if(p.second == y) break;

        for(auto edge : edges[p.second])
        {
            if(cost[edge.first] > -p.first + edge.second)
            {
                cost[edge.first] = -p.first + edge.second;
                q.push({-cost[edge.first], edge.first});
            }
        }
    }
    int ans1 = cost[y];
    if(ans1 == INT_MAX) ans1 = -1;

    // y->z
    if(ans1 != -1)
    {
        fill(cost.begin(), cost.end(), INT_MAX);
        while(!q.empty()) q.pop();

        cost[y] = 0;
        q.push({0, y});

        while(!q.empty())
        {
            auto p = q.top();
            q.pop();

            if(p.second == z) break;

            for(auto edge : edges[p.second])
            {
                if(cost[edge.first] > -p.first + edge.second)
                {
                    cost[edge.first] = -p.first + edge.second;
                    q.push({-cost[edge.first], edge.first});
                }
            }
        }
        if(cost[z] == INT_MAX) ans1 = -1;
        else ans1 += cost[z];
    }


    // y를 제외한 경우
    fill(cost.begin(), cost.end(), INT_MAX);
    while(!q.empty()) q.pop();

    cost[x] = 0;
    q.push({0, x});

    while(!q.empty())
    {
        auto p = q.top();
        q.pop();

        if(p.second == z) break;

        for(auto edge : edges[p.second])
        {
            if(edge.first == y) continue;
            if(cost[edge.first] > -p.first + edge.second)
            {
                cost[edge.first] = -p.first + edge.second;
                q.push({-cost[edge.first], edge.first});
            }
        }
    }

    int ans2 = cost[z];
    if(ans2 == INT_MAX) ans2 = -1;
    
    cout<<ans1<<" "<<ans2;
}   
