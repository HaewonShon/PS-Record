#include <bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;

    vector<string> board(BOARD_SIZE);
    for(int i = 0; i < BOARD_SIZE; ++i) cin>>board[i];

    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
        {
            if(board[i][j] == 'o')
            {
                for(int index = 0; index < BOARD_SIZE; ++index)
                {
                    if(board[i][index] != 'o') board[i][index] = 'O';
                    if(board[index][j] != 'o') board[index][j] = 'O';
                }
            }
        }
    }

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1, 1};

    if(board[r-1][c-1] == 'x')
    {
        cout<<0;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({r-1, c-1});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        for(int k = 0; k < 4; ++k)
        {
            int x = p.second + xOffset[k];
            int y = p.first + yOffset[k];

            if(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE)
            {
                if(board[y][x] == 'x')
                {
                    cout<<(abs(y - (r-1))) + abs(x - (c-1));
                    return 0;
                }

                if(board[y][x] != ' ')
                q.push({y, x});
                board[y][x] = ' ';  
            }
        }
    }
        
}