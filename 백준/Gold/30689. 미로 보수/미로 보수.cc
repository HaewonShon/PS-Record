#include <bits/stdc++.h>
using namespace std;

int visited[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<string> dir(n);
    vector<vector<int>> cost(n, vector<int>(m));

    for(int i = 0; i < n; ++i)
    {
        cin>>dir[i];
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>cost[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));

    int ans = 0;
    int tries = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(visited[i][j] == 0)
            {
                ++tries;

                int x = j, y = i;

                while((y >= 0 && y < n) && (x >= 0 && x < m))
                {
                    if(visited[y][x] == 0)
                    {
                        visited[y][x] = tries;
                        
                        if(dir[y][x] == 'L') --x;
                        else if(dir[y][x] == 'R') ++x;
                        else if(dir[y][x] == 'U') --y;
                        else if(dir[y][x] == 'D') ++y;
                    }
                    else if(visited[y][x] == tries) // 순환 - 사이클 내 최저비용 찾기
                    {
                        int minCost = cost[y][x];

                        int _x = x, _y = y;

                        do
                        {
                            minCost = min(minCost, cost[_y][_x]);

                            if(dir[_y][_x] == 'L') --_x;
                            else if(dir[_y][_x] == 'R') ++_x;
                            else if(dir[_y][_x] == 'U') --_y;
                            else if(dir[_y][_x] == 'D') ++_y;
                        } while(_x != x || _y != y);
                         
                        ans += minCost;
                        break;
                    }
                    else // 이미 mapping된 경로와 만남-추가비용 x
                    {
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
}
