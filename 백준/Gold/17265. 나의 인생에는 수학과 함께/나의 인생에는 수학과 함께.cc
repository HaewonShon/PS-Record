#include <bits/stdc++.h>
using namespace std;

int Calc(int lhs, char rhs, char op)
{
    rhs -= '0';
    if(op == '+') return lhs + rhs;
    if(op == '-') return lhs - rhs;
    if(op == '*') return lhs * rhs;
    return -1;
}

void DFS(const vector<vector<char>>& board, int n, int i, int j, int currVal, char op, vector<int>& res)
{
    if(i == n-1 && j == n-1)
    {
        return res.push_back(Calc(currVal, board[i][j], op));
    }

    if((i + j) % 2 == 0) // num
    {
        currVal = Calc(currVal, board[i][j], op);
        if(i < n-1) DFS(board, n, i+1, j, currVal, ' ', res);
        if(j < n-1) DFS(board, n, i, j+1, currVal, ' ', res);
    }
    else // op
    {
        if(i < n-1) DFS(board, n, i+1, j, currVal, board[i][j], res);
        if(j < n-1) DFS(board, n, i, j+1, currVal, board[i][j], res);
    }
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) 
            cin>>board[i][j];

    vector<int> res;
    DFS(board, n, 0, 0, 0, '+', res);
    
    sort(res.begin(), res.end());
    cout<<res.back()<<" "<<res.front();
}