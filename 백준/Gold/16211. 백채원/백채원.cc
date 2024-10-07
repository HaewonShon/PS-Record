#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<pair<int, int>>> edges(n+1);
    while(m--)
    {
        int a, b, cost;
        cin>>a>>b>>cost;

        edges[a].push_back({b, cost});
        edges[b].push_back({a, cost});
    }

    vector<int> distFromK(n+1, INT_MAX);
    priority_queue<pair<int, int>> q;
    while(k--)
    {
        int start;
        cin>>start;
        distFromK[start] = 0;
        q.push({0, start});
    }

    // k->각 지점 최단거리 구하기
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();

        if(-p.first > distFromK[p.second])
        {
            continue;
        }

        for(auto next : edges[p.second])
        {
            int cost = -p.first + next.second;
            if(distFromK[next.first] > cost)
            {
                distFromK[next.first] = cost;
                q.push({-cost, next.first});
            }
        }
    }

    // 백채원->각 지점 최단거리 구하기. k가 방문하는 시간 전에만 가능.
    vector<int> distFromC(n+1, INT_MAX);
    distFromC[1] = 0;
    q.push({0, 1});
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();

        if(-p.first > distFromC[p.second])
        {
            continue;
        }

        for(auto next : edges[p.second])
        {
            int cost = -p.first + next.second;
            if(distFromC[next.first] > cost && distFromK[next.first] > cost)
            {
                distFromC[next.first] = cost;
                q.push({-cost, next.first});
            }
        }
    } 

    bool hasAns = false;
    for(int i = 2; i <= n; ++i)
    {
        if(distFromC[i] != INT_MAX)
        {
            hasAns = true;
            cout<<i<<" ";
        }
    }

    if(hasAns == false)
    {
        cout<<0;
    }
}
