#include <bits/stdc++.h>
using namespace std;

bool IsValidPos(int i, int j)
{
    if(i >= 0 && i < 6 && j >= 0 && j < 6) return true;
    return false;
}

void Flip(vector<vector<char>>& board, int i, int j, int iOffset, int jOffset, char target)
{
    if(iOffset == 0 && jOffset == 0) return;

    for(int dist = 1; dist <= 6; ++dist)
    {
        int _i = i + iOffset * dist;
        int _j = j + jOffset * dist;
        if(!IsValidPos(_i, _j)) return;
        if(board[_i][_j] == '.') return;
        
        // 뒤집어야하는 범위 발견
        if(board[_i][_j] == target)
        {
            while(--dist > 0)
            {
                board[i + iOffset * dist][j + jOffset * dist] = target;
            }
            return;
        }
    }
}

void Simulate(vector<vector<char>>& board, bool isBlackTurn, int i, int j)
{
    char target = isBlackTurn ? 'B' : 'W';
    board[i][j] = target;
    for(int iOffset = -1; iOffset <= 1; ++iOffset)
    {
        for(int jOffset = -1; jOffset <= 1; ++jOffset)
        {
            Flip(board, i, j, iOffset, jOffset, target);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<vector<char>> board(6, vector<char>(6, '.'));
    board[2][2] = 'W';
    board[2][3] = 'B';
    board[3][2] = 'B';
    board[3][3] = 'W';

    bool isBlackTurn = true;
    while(n--)
    {
        int i, j;
        cin>>i>>j;
        --i;
        --j;

        Simulate(board, isBlackTurn, i, j);
        isBlackTurn = !isBlackTurn;
    }

    int whites = 0, blacks = 0;
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            cout<<board[i][j];
            if(board[i][j] == 'W') ++whites;
            else if(board[i][j] == 'B') ++blacks;
        }
        cout<<endl;
    }
    if(whites > blacks) cout<<"White";
    else cout<<"Black";
}
