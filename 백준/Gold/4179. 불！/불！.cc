#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;

    vector<string> board(r);

    for(int i = 0; i < r; ++i) cin>>board[i];

    queue<pair<int, int>> jihoonQ;
    queue<pair<int, int>> fireQ;

    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(board[i][j] == 'J') jihoonQ.push({i, j});
            else if(board[i][j] == 'F') fireQ.push({i, j});
        }
    }

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1, 1};

    int time = 0;

    while(!jihoonQ.empty())
    {
        ++time;

        // fire spread
        int fireQSize = fireQ.size();
        for(int i = 0; i < fireQSize; ++i)
        {
            auto pos = fireQ.front();
            fireQ.pop();

            for(int j = 0; j < 4; ++j)
            {
                auto nextPos = pos;
                nextPos.first += yOffset[j];
                nextPos.second += xOffset[j];

                if(nextPos.first >= 0 && nextPos.first < r && nextPos.second >= 0 && nextPos.second < c)
                {
                    if(board[nextPos.first][nextPos.second] == '.' || board[nextPos.first][nextPos.second] == 'J' || board[nextPos.first][nextPos.second] == 'x')
                    {
                        board[nextPos.first][nextPos.second] = 'F';
                        fireQ.push(nextPos);
                    }
                }
            }
        }

        // jihoon move
        int JihoonQSize = jihoonQ.size();
        for(int i = 0; i < JihoonQSize; ++i)
        {
            auto pos = jihoonQ.front();
            jihoonQ.pop();

            if(pos.first == 0 || pos.first == r-1 || pos.second == 0 || pos.second == c-1) // exit
            {
                cout<<time;
                return 0;
            }

            for(int j = 0; j < 4; ++j)
            {
                auto nextPos = pos;
                nextPos.first += yOffset[j];
                nextPos.second += xOffset[j];

                if(nextPos.first >= 0 && nextPos.first < r && nextPos.second >= 0 && nextPos.second < c)
                {
                    if(board[nextPos.first][nextPos.second] == '.')
                    {
                        board[nextPos.first][nextPos.second] = 'x';
                        jihoonQ.push(nextPos);
                    }
                }
            }
        }
    }

    cout<<"IMPOSSIBLE";
}