#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> amountOfOil(m);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(land[i][j] == 1)
            {
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                land[i][j] = 0;
                
                int minJ = j, maxJ = j;
                
                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    minJ = min(minJ, p.second);
                    maxJ = max(maxJ, p.second);
                    ++size;
                    
                    if(p.first > 0 && land[p.first-1][p.second] == 1)
                    {
                        land[p.first-1][p.second] = 0;
                        q.push({p.first-1, p.second});
                    }
                    if(p.first < n-1 && land[p.first+1][p.second] == 1)
                    {
                        land[p.first+1][p.second] = 0;
                        q.push({p.first+1, p.second});
                    }
                    if(p.second > 0 && land[p.first][p.second-1] == 1)
                    {
                        land[p.first][p.second-1] = 0;
                        q.push({p.first, p.second-1});
                    }
                    if(p.second < m-1 && land[p.first][p.second+1] == 1)
                    {
                        land[p.first][p.second+1] = 0;
                        q.push({p.first, p.second+1});
                    }
                }
                
                for(int currJ = minJ; currJ <= maxJ; ++currJ)
                {
                    amountOfOil[currJ].push_back(size);
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < m; ++i)
    {
        int sumOfOil = std::accumulate(amountOfOil[i].begin(), amountOfOil[i].end(), 0);
        answer = max(answer, sumOfOil);
    }
    
    return answer;
}