#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
        }
    }
    int k;
    cin>>k;

    priority_queue<pair<int, pair<int, int>>> q;
    for(int j = 0; j < m; ++j)
    {
        if(board[0][j] != 0) q.push({board[0][j], {0, j}});
        board[0][j] = 0;
        if(board[n-1][j] != 0) q.push({board[n-1][j], {n-1, j}});
        board[n-1][j] = 0;
    }   
    for(int i = 1; i < n-1; ++i)
    {
        if(board[i][0] != 0) q.push({board[i][0], {i, 0}});
        board[i][0] = 0;
        if(board[i][m-1] != 0) q.push({board[i][m-1], {i, m-1}});
        board[i][m-1] = 0;
    }

    int count = 0;
    int ans = 0;
    while(!q.empty() && count < k)
    {
        auto next = q.top();
        int i = next.second.first;
        int j = next.second.second;
        q.pop();

        cout<<i+1<<" "<<j+1<<"\n";

        ++count;
        ans += next.first;

        if(i > 0 && board[i-1][j] != 0)
        {
            q.push({board[i-1][j], {i-1, j}});
            board[i-1][j] = 0;
        }
        if(i < n-1 && board[i+1][j] != 0)
        {
            q.push({board[i+1][j], {i+1, j}});
            board[i+1][j] = 0;
        }
        if(j > 0 && board[i][j-1] != 0)
        {
            q.push({board[i][j-1], {i, j-1}});
            board[i][j-1] = 0;
        }
        if(j < m-1 && board[i][j+1] != 0)
        {
            q.push({board[i][j+1], {i, j+1}});
            board[i][j+1] = 0;
        }
    }
}
