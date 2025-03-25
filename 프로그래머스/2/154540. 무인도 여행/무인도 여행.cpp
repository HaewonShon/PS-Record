#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int width = maps[0].length();
    int height = maps.size();
    
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if(maps[i][j] != 'X')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                
                int foods = maps[i][j] - '0';
                maps[i][j] = 'X';
                
                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    
                    if(p.first > 0 && maps[p.first-1][p.second] != 'X')
                    {
                        foods += maps[p.first-1][p.second] - '0';
                        q.push({p.first-1, p.second});
                        maps[p.first-1][p.second] = 'X';
                    }
                    if(p.first < height-1 && maps[p.first+1][p.second] != 'X')
                    {
                        foods += maps[p.first+1][p.second] - '0';
                        q.push({p.first+1, p.second});
                        maps[p.first+1][p.second] = 'X';
                    }
                    if(p.second > 0 && maps[p.first][p.second-1] != 'X')
                    {
                        foods += maps[p.first][p.second-1] - '0';
                        q.push({p.first, p.second-1});
                        maps[p.first][p.second-1] = 'X';
                    }
                    if(p.second < width-1 && maps[p.first][p.second+1] != 'X')
                    {
                        foods += maps[p.first][p.second+1] - '0';
                        q.push({p.first, p.second+1});
                        maps[p.first][p.second+1] = 'X';
                    }
                }
                
                answer.push_back(foods);
            }
        }
    }
    
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}