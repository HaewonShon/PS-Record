#include <bits/stdc++.h>
using namespace std;

int GetLength(char board[][20], int y, int x, pair<int, int> dir)
{
    int len1 = 0;
    int len2 = 0;

    int _y = y + dir.first;
    int _x = x + dir.second;

    while(_y > 0 && _y <= 19 && _x > 0 && _x <= 19)
    {
        if(board[_y][_x] != board[y][x]) break;
        ++len1;
        _y += dir.first;
        _x += dir.second;
    }
    
    _y = y - dir.first;
    _x = x - dir.second;
     
    while(_y > 0 && _y <= 19 && _x > 0 && _x <= 19)
    {
        if(board[_y][_x] != board[y][x]) break;
        ++len2;
        _y -= dir.first;
        _x -= dir.second;
    }

    return len1 + len2 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    char board[20][20];

    memset(board, -1, sizeof(board));

    int turn = 1;
    for(; turn <= n; ++turn)
    {
        int y, x;
        cin>>y>>x;
        if(turn % 2 == 1) // 흑
        {
            board[y][x] = 1;
        }
        else // 백
        {
            board[y][x] = 0;
        }

        // 가로
        if(GetLength(board, y, x, {0, 1}) == 5) break;
        // 세로
        if(GetLength(board, y, x, {1, 0}) == 5) break;
        // 우상단 대각
        if(GetLength(board, y, x, {1, 1}) == 5) break;
        // 좌상단 대각
        if(GetLength(board, y, x, {1, -1}) == 5) break;
    }

    if(turn > n)
    {
        cout<<-1;
    }
    else
    {
        cout<<turn;
    }
}