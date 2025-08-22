#include <bits/stdc++.h>
using namespace std;

int board[50][50];

const int UNAVAILABLE = 0;
const int EMPTY = 1;
const int GREEN = 3;
const int RED = 4;
const int FLOWER = -1;

int xOffset[4] = {-1, 1, 0, 0};
int yOffset[4] = {0, 0, -1, 1};

void Simulate(int n, int m, int& ans)
{
    int simulation[50][50];
    memcpy(simulation, board, sizeof(board));

    queue<pair<int, int>> q;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(simulation[i][j] == GREEN || simulation[i][j] == RED)
            {
                q.push({i, j});
            }
        }
    }

    int turn = 0;
    while(!q.empty())
    {
        int qSize = q.size();

        while(qSize--)
        {
            auto pos = q.front();
            q.pop();

            if(simulation[pos.first][pos.second] == FLOWER || simulation[pos.first][pos.second] == UNAVAILABLE)
            {
                continue;
            }
            
            for(int i = 0; i < 4; ++i)
            {
                auto nextPos = pos;
                nextPos.first += yOffset[i];
                nextPos.second += xOffset[i];
                if(nextPos.first < 0 || nextPos.first >= n || nextPos.second < 0 || nextPos.second >= m) continue;

                if(simulation[nextPos.first][nextPos.second] == EMPTY)
                {
                    simulation[nextPos.first][nextPos.second] = simulation[pos.first][pos.second] + 2;
                    q.push(nextPos);
                }
                else if((simulation[pos.first][pos.second] == turn * 2 + GREEN && simulation[nextPos.first][nextPos.second] == (turn + 1) * 2 + RED)
                    || (simulation[pos.first][pos.second] == turn * 2 + RED && simulation[nextPos.first][nextPos.second] == (turn + 1) * 2 + GREEN))
                {
                    simulation[nextPos.first][nextPos.second] = FLOWER;   
                }
            }
            simulation[pos.first][pos.second] = UNAVAILABLE;
        }
        ++turn;
    }

    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(simulation[i][j] == FLOWER) ++res;
        }
    }

    ans = max(ans, res);
}

void Search(int n, int m, vector<pair<int, int>>& candidate, int index, int g, int r, int& ans)
{
    if(g == 0 && r == 0)
    {
        Simulate(n, m, ans);
        return;
    }

    if(index == candidate.size())
    {
        return;
    }

    auto pos = candidate[index];
    if(g > 0)
    {
        board[pos.first][pos.second] = GREEN;
        Search(n, m, candidate, index + 1, g - 1, r, ans);
        board[pos.first][pos.second] = EMPTY;
    }
    if(r > 0)
    {
        board[pos.first][pos.second] = RED;
        Search(n, m, candidate, index + 1, g, r - 1, ans);
        board[pos.first][pos.second] = EMPTY;
    }
    Search(n, m, candidate, index + 1, g, r, ans);
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));

    int n, m;
    cin>>n>>m;

    int g, r;
    cin>>g>>r;

    vector<pair<int, int>> candidate;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
            if(board[i][j] == 2)
            {
                candidate.push_back({i, j});
                board[i][j] = EMPTY;
            }
        }
    }

    int ans = 0;
    Search(n, m, candidate, 0, g, r, ans);
    cout<<ans;
}