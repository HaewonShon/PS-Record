#include <bits/stdc++.h>
using namespace std;

int res[501][501];

int DFS(const vector<vector<int>>& board, int i, int j, int n)
{
    if(res[i][j] != -1) return res[i][j];

    int searchRes = 0;
    if(i > 0 && board[i-1][j] > board[i][j]) searchRes = max(searchRes, DFS(board, i-1, j, n));
    if(i < n-1 && board[i+1][j] > board[i][j]) searchRes = max(searchRes, DFS(board, i+1, j, n));
    if(j > 0 && board[i][j-1] > board[i][j]) searchRes = max(searchRes, DFS(board, i, j-1, n));
    if(j < n-1 && board[i][j+1] > board[i][j]) searchRes = max(searchRes, DFS(board, i, j+1, n));

    res[i][j] = searchRes + 1;
    return res[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>board[i][j];
        }
    }

    memset(res, -1, sizeof(res));

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ans = max(ans, DFS(board, i, j, n));
        }
    }
    cout<<ans;
}