#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    string s;
    cin>>s;

    pair<int, int> pos = {0, 0}; // { y, x }

    for(char c : s)
    {
        pair<int, int> next = pos; // { y, x }
        if(c == 'U') next.first += -1;
        else if(c == 'D') next.first += 1;
        else if(c == 'L') next.second += -1;
        else if(c == 'R') next.second += 1;

        if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
        {
            continue;
        }

        if(c == 'U' || c == 'D') // 세로
        {
            if(board[pos.first][pos.second] == '-')
            {
                board[pos.first][pos.second] = '+';
            }
            else if(board[pos.first][pos.second] == '.')
            {
                board[pos.first][pos.second] = '|';
            }

            if(board[next.first][next.second] == '-')
            {
                board[next.first][next.second] = '+';
            }
            else if(board[next.first][next.second] == '.')
            {
                board[next.first][next.second] = '|';
            }
        }
        else // 가로
        {
            
            if(board[pos.first][pos.second] == '|')
            {
                board[pos.first][pos.second] = '+';
            }
            else if(board[pos.first][pos.second] == '.')
            {
                board[pos.first][pos.second] = '-';
            }

            if(board[next.first][next.second] == '|')
            {
                board[next.first][next.second] = '+';
            }
            else if(board[next.first][next.second] == '.')
            {
                board[next.first][next.second] = '-';
            }
        }

        pos = next;
    }

    for(auto& row : board)
    {
        for(char c : row)
        {
            cout<<c;
        }
        cout<<endl;
    }
}   