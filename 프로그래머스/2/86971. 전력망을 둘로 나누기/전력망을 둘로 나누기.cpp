#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    
    vector<vector<bool>> isConnected(n+1, vector<bool>(n+1, false));
    for(auto p : wires)
    {
        isConnected[p[0]][p[1]] = true;
        isConnected[p[1]][p[0]] = true;
    }
    
    int answer = 1e9;
    for(auto p : wires)
    {
        isConnected[p[0]][p[1]] = false;
        isConnected[p[1]][p[0]] = false;
        
        vector<bool> isVisited(n+1, false);
        queue<int> q;
        isVisited[1] = true;
        q.push(1);
        
        int groupSize = 0;        
        while(!q.empty())
        {
            int node = q.front();
            ++groupSize;
            q.pop();
            
            for(int i = 1; i <= n; ++i)
            {
                if(isConnected[node][i] && !isVisited[i])
                {
                    q.push(i);
                    isVisited[i] = true;
                }
            }
        }
        
        answer = min(answer, abs(groupSize - (n-groupSize)));
        
        isConnected[p[0]][p[1]] = true;
        isConnected[p[1]][p[0]] = true;
    }
    
    return answer;
}