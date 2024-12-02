#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;

char inEdgeCount[1'000'001];

vector<int> solution(vector<vector<int>> edges) {
    
    vector<int> answer(4);
    
    int n = 0;
    memset(inEdgeCount, 0, sizeof(inEdgeCount));
    
    unordered_map<int, vector<int>> e;
    for(auto& edge : edges)
    {
        e[edge[0]].push_back(edge[1]);
        n = max(n, max(edge[0], edge[1]));
        ++inEdgeCount[edge[1]];
    }
    
    vector<bool> visited(n + 1, false);

    for(int start = 1; start <= n; ++start)
    {
        if(visited[start]) continue;
        
        if(e[start].size() >= 2 && inEdgeCount[start] == 0)
        {
            answer[0] = start;
            continue;
        }
        
        if(e[start].size() == 0 && inEdgeCount[start] == 0) continue;
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        bool is8graph = false;
        while(!q.empty())
        {
            int next = q.front();
            q.pop();
            
            if(e[next].size() == 0)
            {
                ++answer[2];
            }
            
            if(e[next].size() == 2)
            {
                is8graph = true;
            }
            
            for(int neighbor : e[next])
            {
                if(neighbor == start && !is8graph)
                {
                    ++answer[1];
                    break;
                }
                else if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        if(is8graph) ++answer[3];
    }
    
    return answer;
}