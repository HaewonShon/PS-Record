#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;

    vector<string> board(r);
    vector<vector<int>> waterArrival(r, vector<int>(c, INT_MAX));
    for(int i = 0; i < r; ++i) cin>>board[i];

    // bfs for water
    {
        queue<pair<int, int>> q;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(board[i][j] == '*')
                {
                    q.push({i, j});
                    waterArrival[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;

            if(i > 0 && board[i-1][j] == '.' && waterArrival[i-1][j] == INT_MAX)
            {
                waterArrival[i-1][j] = waterArrival[i][j] + 1;
                q.push({i-1, j});
            }
            if(i < r-1 && board[i+1][j] == '.' && waterArrival[i+1][j] == INT_MAX)
            {
                waterArrival[i+1][j] = waterArrival[i][j] + 1;
                q.push({i+1, j});
            }
            if(j > 0 && board[i][j-1] == '.' && waterArrival[i][j-1] == INT_MAX)
            {
                waterArrival[i][j-1] = waterArrival[i][j] + 1;
                q.push({i, j-1});
            }
            if(j < c-1 && board[i][j+1] == '.' && waterArrival[i][j+1] == INT_MAX)
            {
                waterArrival[i][j+1] = waterArrival[i][j] + 1;
                q.push({i, j+1});
            }
        }
    }

    // bfs for hedgehog
    {
        queue<pair<pair<int, int>, int>> q; // {pos, time}}
        for(int i = 0; i < r && q.empty(); ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(board[i][j] == 'S')
                {
                    q.push({{i, j}, 0});
                    board[i][j] = 'X';
                    break;
                }
            }
        }

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            int i = p.first.first;
            int j = p.first.second;
            int currentTime = p.second + 1;

            if(i > 0 && board[i-1][j] != 'X' && waterArrival[i-1][j] > currentTime)
            {
                if(board[i-1][j] == 'D')
                {
                    cout<<currentTime;
                    return 0;
                }

                board[i-1][j] = 'X';
                q.push({{i-1, j}, currentTime});
            }
            if(i < r-1 && board[i+1][j] != 'X' && waterArrival[i+1][j] > currentTime)
            {
                if(board[i+1][j] == 'D')
                {
                    cout<<currentTime;
                    return 0;
                }

                board[i+1][j] = 'X';
                q.push({{i+1, j}, currentTime});
            }
            if(j > 0 && board[i][j-1] != 'X' && waterArrival[i][j-1] > currentTime)
            {
                if(board[i][j-1] == 'D')
                {
                    cout<<currentTime;
                    return 0;
                }

                board[i][j-1] = 'X';
                q.push({{i, j-1}, currentTime});
            }
            if(j < c-1 && board[i][j+1] != 'X' && waterArrival[i][j+1] > currentTime)
            {
                if(board[i][j+1] == 'D')
                {
                    cout<<currentTime;
                    return 0;
                }

                board[i][j+1] = 'X';
                q.push({{i, j+1}, currentTime});
            }
        }
    }

    cout<<"KAKTUS";
}