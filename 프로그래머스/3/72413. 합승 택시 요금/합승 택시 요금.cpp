#include <string>
#include <vector>
#include <queue>

using namespace std;

void Dijkstra(int start, const vector<vector<pair<int, int>>>& edges, vector<int>& res)
{
    priority_queue<pair<int, int>> q; // {-cost, target}
    q.push({0, start});
    res[start] = 0;
    
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        
        for(auto& e : edges[p.second])
        {
            int cost = -p.first + e.second;
            if(cost < res[e.first])
            {
                q.push({-cost, e.first});
                res[e.first] = cost;
            }
        }
    }    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<pair<int, int>>> edges(n+1);
    for(auto& e : fares)
    {
        edges[e[0]].push_back({e[1], e[2]});
        edges[e[1]].push_back({e[0], e[2]});
    }
        
    vector<vector<int>> dist(3, vector<int>(n+1, 1e8));
    
    Dijkstra(s, edges, dist[0]);
    Dijkstra(a, edges, dist[1]);
    Dijkstra(b, edges, dist[2]);
    
    // ans = s->x까지 합승, x->a x->b 따로 가거나, s->a, s->b 따로 가는 경우 중 최솟값
        
    int answer = dist[0][a] + dist[0][b];
    for(int i = 1; i <= n; ++i)
    {
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    
    return answer;
}