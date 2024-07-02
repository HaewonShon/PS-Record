#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int y, x;
};

bool operator==(Point& p1, Point& p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}

struct Info
{
    Point red, blue;
    int turn;
};

Info MoveVertically(vector<string>& board, Info info, bool isUp);
Info MoveHorizontally(vector<string>& board, Info info, bool isLeft);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin>>h>>w;

    vector<string> board(h);
    Point red, blue, hole;

    for(int i = 0; i < h; ++i)
    {
        cin>>board[i];
        for(int j = 0; j < w; ++j)
        {
            if(board[i][j] == 'R')
            {
                red = {i, j};
                board[i][j] == '.';
            }
            else if(board[i][j] == 'B')
            {
                blue = {i, j};
                board[i][j] == '.';
            }
            else if(board[i][j] == 'O')
            {
                hole = {i, j};
            }
        }
    }

    queue<Info> q;
    q.push({red, blue, 0});

    while(!q.empty())
    {
        Info info = q.front();
        q.pop();
        ++info.turn;

        if(info.turn > 10)
        {
            break;
        }

        Info res[4] = { MoveVertically(board, info, true),
                        MoveVertically(board, info, false),
                        MoveHorizontally(board, info, true),
                        MoveHorizontally(board, info, false) };

        for(int i = 0; i < 4; ++i)
        {
            if(res[i].red == hole && !(res[i].red == res[i].blue))
            {
                cout<<info.turn;
                return 0;
            }
            else if(res[i].blue == hole)
            {
                continue;
            }
            else
            {
                if(res[i].red == info.red && res[i].blue == info.blue)
                {
                    continue;
                }
                else
                {
                    q.push(res[i]);
                }
            }
        }
    }

    cout<<-1;
}   

Info MoveVertically(vector<string>& board, Info info, bool isUp)
{
    int offset = (isUp) ? -1 : 1;
    bool isRedFirst = (isUp) ? info.red.y < info.blue.y : info.red.y > info.blue.y;

    while(board[info.red.y][info.red.x] != 'O' && board[info.red.y + offset][info.red.x] != '#')
    {
        info.red.y += offset;
    }
    while(board[info.blue.y][info.blue.x] != 'O' && board[info.blue.y + offset][info.blue.x] != '#')
    {
        info.blue.y += offset;
    }
 
    if(info.red == info.blue && board[info.red.y][info.red.x] != 'O')
    {
        if(isRedFirst)
        {
            info.blue.y -= offset;
        }
        else
        {
            info.red.y -= offset;
        }
    }

    return info;
}

Info MoveHorizontally(vector<string>& board, Info info, bool isLeft)
{
    int offset = (isLeft) ? -1 : 1;
    bool isRedFirst = (isLeft) ? info.red.x < info.blue.x : info.red.x > info.blue.x;

    while(board[info.red.y][info.red.x] != 'O' && board[info.red.y][info.red.x + offset] != '#')
    {
        info.red.x += offset;
    }
    while(board[info.blue.y][info.blue.x] != 'O' && board[info.blue.y][info.blue.x + offset] != '#')
    {
        info.blue.x += offset;
    }
 
    if(info.red == info.blue && board[info.red.y][info.red.x] != 'O')
    {
        if(isRedFirst)
        {
            info.blue.x -= offset;
        }
        else
        {
            info.red.x -= offset;
        }
    }

    return info;
}