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

    int groupNum = 0;
    int maxGroupSize = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] == 1)
            {
                int groupSize = 0;

                queue<pair<int, int>> q;
                board[i][j] = 0;
                q.push({i, j});

                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    ++groupSize;

                    if(p.first > 0 && board[p.first-1][p.second] == 1)
                    {
                        q.push({p.first-1, p.second});
                        board[p.first-1][p.second] = 0;
                    }
                    if(p.first < n-1 && board[p.first+1][p.second] == 1)
                    {
                        q.push({p.first+1, p.second});
                        board[p.first+1][p.second] = 0;
                    }

                    if(p.second > 0 && board[p.first][p.second-1] == 1)
                    {
                        q.push({p.first, p.second-1});
                        board[p.first][p.second-1] = 0;
                    }
                    if(p.second < m-1 && board[p.first][p.second+1] == 1)
                    {
                        q.push({p.first, p.second+1});
                        board[p.first][p.second+1] = 0;
                    }
                }

                maxGroupSize = max(maxGroupSize, groupSize);
                ++groupNum;
            }
        }
    }


    cout<<groupNum<<"\n"<<maxGroupSize;
}