#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;

    vector<string> map(r);
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for(int i = 0; i < r; ++i)
    {
        cin>>map[i];
    }
    int xOffset[4] = {0, 0, -1, 1};
    int yOffset[4] = {-1, 1, 0, 0};

    unordered_map<char, vector<pair<int, int>>> offset;
    offset['+'] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    offset['-'] = {{0, -1}, {0, 1}};
    offset['|'] = {{-1, 0}, {1, 0}};
    offset['1'] = {{1, 0}, {0, 1}};
    offset['2'] = {{-1, 0}, {0, 1}};
    offset['3'] = {{-1, 0}, {0, -1}};
    offset['4'] = {{1, 0}, {0, -1}};

    bool ZhasConnected = false;

    queue<pair<int, int>> q;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(map[i][j] == 'M')
            {
                visited[i][j] = true;
                for(int k = 0; k < 4; ++k)
                {
                    int nextY = i + yOffset[k];
                    int nextX = j + xOffset[k];

                    if(nextY < 0 || nextY >= r || nextX < 0 || nextX >= c)
                    {
                        continue;
                    }

                    if(map[nextY][nextX] != '.')
                    {
                        // next랑 curr가 연결되어있는지?
                        for(auto p : offset[map[nextY][nextX]])
                        {
                            if(nextY + p.first == i && nextX + p.second == j)
                            {
                                q.push({nextY, nextX});
                                visited[nextY][nextX] = true;
                                break;
                            }
                        }                        
                    }
                }
            }
            else if(map[i][j] == 'Z')
            {
                visited[i][j] = true;
                for(int k = 0; k < 4; ++k)
                {
                    int nextY = i + yOffset[k];
                    int nextX = j + xOffset[k];

                    if(nextY < 0 || nextY >= r || nextX < 0 || nextX >= c)
                    {
                        continue;
                    }

                    // next랑 curr가 연결되어있는지?
                    if(map[nextY][nextX] != '.')
                    {
                        for(auto p : offset[map[nextY][nextX]])
                        {
                            if(nextY + p.first == i && nextX + p.second == j)
                            {
                                ZhasConnected = true;
                                visited[nextY][nextX] = true;
                                break;
                            }
                        }
                    } 
                }
            }
        }
    }

    if(!ZhasConnected)
    {
        offset['Z'] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    }

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if(map[curr.first][curr.second] == 'Z')
        {
            continue;
        }

        for(auto p : offset[map[curr.first][curr.second]])
        {
            int _y = curr.first + p.first;
            int _x = curr.second + p.second;

            if(visited[_y][_x])
            {
                continue;
            }

            if(map[_y][_x] == '.')
            {
                int flag = 0;
                for(int i = 0; i < 4; ++i)
                {
                    int nextY = _y + yOffset[i];
                    int nextX = _x + xOffset[i];

                    if(nextY < 0 || nextY >= r || nextX < 0 || nextX >= c)
                    {
                        continue;
                    }

                    for(auto nextP : offset[map[nextY][nextX]])
                    {
                        if(nextY + nextP.first == _y && nextX + nextP.second == _x)
                        {
                            flag |= (1 << i);
                            break;
                        }
                    }
                }
                char res = 0;
                if(flag == 0b1111) res = '+';
                else if(flag == 0b1100) res = '-';
                else if(flag == 0b0011) res = '|';
                else if(flag == 0b1010) res = '1';
                else if(flag == 0b1001) res = '2';
                else if(flag == 0b0101) res = '3';
                else if(flag == 0b0110) res = '4';

                cout<<_y + 1<<" "<<_x + 1<<" "<<res<<"\n";

                return 0;
            }
            else
            {
                visited[_y][_x] = true;
                q.push({_y, _x});
            }            
        }
    }
}   