#include <bits/stdc++.h>
using namespace std;

struct Step
{
    int r, c, k, turn;
};

int visited[1000][1000]; // 방문 시점 소모 k횟수

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited, 0x7f, sizeof(visited));

    int n, m, k;
    cin>>n>>m>>k;

    vector<string> board(n);
    for(int i = 0; i < n; ++i) cin>>board[i];

    queue<Step> q;
    q.push({0, 0, 0, 1});
    visited[0][0] = 0;

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1 ,1};

    while(!q.empty())
    {
        Step s = q.front();
        q.pop();

        if(s.r == n-1 && s.c == m-1)
        {
            cout<<s.turn;
            return 0;
        }

        for(int i = 0; i < 4; ++i)
        {
            int r = s.r, c = s.c;
            r += yOffset[i];
            c += xOffset[i];

            if(r >= 0 && r < n && c >= 0 && c < m)
            {
                if(board[r][c] == '0' && visited[r][c] > s.k)
                {
                    visited[r][c] = s.k;
                    q.push({r, c, s.k, s.turn + 1});
                }
                else if(board[r][c] == '1' && s.k < k && visited[r][c] > s.k + 1)
                {
                    visited[r][c] = s.k + 1;
                    q.push({r, c, s.k + 1, s.turn + 1});
                }
            }
        }
    }

    cout<<-1;
}