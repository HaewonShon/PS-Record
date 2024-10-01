#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<vector<int>>& board, int n, int l, int top, int left)
{
    vector<vector<int>> copy(l, vector<int>(l));
    for(int i = 0; i < l; ++i)
    {
        for(int j = 0; j < l; ++j)
        {
            copy[i][j] = board[i+top][j+left];
        }
    }

    for(int i = 0; i < l; ++i)
    {
        for(int j = 0; j < l; ++j)
        {
            board[top + j][left + l - 1 - i] = copy[i][j];
        }
    }
}

void Firestorm(vector<vector<int>>& board, int n, int l)
{
    for(int i = 0; i < n/l; ++i)
    {
        for(int j = 0; j < n/l; ++j)
        {
            Rotate(board, n, l, i*l, j*l);
        }
    }

    vector<vector<bool>> isMelting(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == 0) continue;

            int nearIce = 0;
            if(i > 0 && board[i-1][j] > 0) ++nearIce;
            if(i < n-1 && board[i+1][j] > 0) ++nearIce;
            if(j > 0 && board[i][j-1] > 0) ++nearIce;
            if(j < n-1 && board[i][j+1] > 0) ++nearIce;

            if(nearIce < 3)
            {
                isMelting[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(isMelting[i][j])
            {
                --board[i][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    n = 1 << n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>board[i][j];
        }
    }

    while(q--)
    {
        int l;
        cin>>l;

        Firestorm(board, n, 1 << l);
    }

    int sum = 0;
    int largest = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] > 0)
            {
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});

                sum += board[i][j];
                board[i][j] = -1;

                while(!q.empty())
                {
                    ++size;
                    auto p = q.front();
                    q.pop();

                    if(p.first > 0 && board[p.first-1][p.second] > 0)
                    {
                        sum += board[p.first-1][p.second];
                        board[p.first-1][p.second] = -1;
                        q.push({p.first-1, p.second});
                    }
                    if(p.first < n-1 && board[p.first+1][p.second] > 0)
                    {
                        sum += board[p.first+1][p.second];
                        board[p.first+1][p.second] = -1;
                        q.push({p.first+1, p.second});
                    }
                    if(p.second > 0 && board[p.first][p.second-1] > 0)
                    {
                        sum += board[p.first][p.second-1];
                        board[p.first][p.second-1] = -1;
                        q.push({p.first, p.second-1});
                    }
                    if(p.second < n-1 && board[p.first][p.second+1] > 0)
                    {
                        sum += board[p.first][p.second+1];
                        board[p.first][p.second+1] = -1;
                        q.push({p.first, p.second+1});
                    }
                }

                largest = max(largest, size);
            }
        }
    }
    cout<<sum<<"\n"<<largest;
}
