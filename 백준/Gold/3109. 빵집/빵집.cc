#include <bits/stdc++.h>
using namespace std;

char board[10001][501];

bool Search(int R, int C, int r, int c)
{
    if(board[r][c] != '.') return false;
    board[r][c] = '*';

    if(c == C) return true;

    if(r > 0 && Search(R, C, r-1, c+1)) return true;
    if(Search(R, C, r, c+1)) return true;
    if(r < R && Search(R, C, r+1, c+1)) return true;
    return false;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;

    for(int i = 1; i <= r; ++i)
    {
        for(int j = 1; j <= c; ++j)
        {
            cin>>board[i][j];
        }
    }

    int res = 0;
    for(int i = 1; i <= r; ++i)
    {
        if(Search(r, c, i, 1)) ++res;
    }

    cout<<res;
}