#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    int k;
    cin>>k;

    vector<vector<int>> board(2*n, vector<int>(2*m, 0));

    while(k--)
    {
        int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;

        if(sx == ex)
        {
            if(sx == 0 || sx == n) continue;
            if(sy > ey) swap(sy, ey);
            for(int y = max(0, 2*sy-1); y <= min(2*m-1, 2*ey-1); ++y)
            {
                board[max(0, 2*sx-1)][y] = 1;
            }
        }
        else
        {
            if(sy == 0 || sy == m) continue;
            if(sx > ex) swap(sx, ex);
            for(int x = max(0, 2*sx-1); x <= min(2*n-1, 2*ex-1); ++x)
            {
                board[x][max(0, 2*sy-1)] = 1;
            }
        }
    }

    int minAns = INT_MAX, maxAns = 0;

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1, 1};

    for(int i = 0; i < 2*n-1; i += 2)
    {
        for(int j = 0; j < 2*m-1; j += 2)
        {
            if(board[i][j] == 0)
            {
                int area = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                board[i][j] = 1;
                
                while(!q.empty())
                {
                    auto p = q.front();
                    if(p.first % 2 == 0 && p.second % 2 == 0)
                    {
                        ++area;
                    }
                    q.pop();

                    for(int index = 0; index < 4; ++index)
                    {
                        auto p2 = p;
                        p2.first += xOffset[index];
                        p2.second += yOffset[index];

                        if(p2.first < 0 || p2.first >= 2*n || p2.second < 0 || p2.second >= 2*m)
                            continue;
                        
                        if(board[p2.first][p2.second] == 0)
                        {
                            board[p2.first][p2.second] = 1;
                            q.push(p2);
                        }
                    }
                }

                maxAns = max(area, maxAns);
                minAns = min(area, minAns);
            }
        }
    }
    cout<<maxAns<<"\n"<<minAns;
}