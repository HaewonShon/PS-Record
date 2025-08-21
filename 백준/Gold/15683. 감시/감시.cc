#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int status[8][8];


void DebugPrint(int n, int m)
{
    cout<<"DEBUG PRINT\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout<<status[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void WatchDir(int i, int j, int xDir, int yDir, int n, int m, bool set)
{
    i += yDir;
    j += xDir;
    while(i >= 0 && i < n && j >= 0 && j < m)
    {
        if(board[i][j] == 6) break;

        if(set) ++status[i][j];
        else --status[i][j];
        
        i += yDir;
        j += xDir;
    }
}

void Search(const vector<pair<int, int>>& camPos, int camIndex, int n, int m, int& ans)
{
    if(camPos.size() == camIndex)
    {
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(board[i][j] == 0 && status[i][j] == 0) ++res;
            }
        }
        ans = min(ans, res);

        return;
    }

    auto pos = camPos[camIndex];
    int camType = board[pos.first][pos.second];

    if(camType == 1)
    {
        // 오른쪽
        WatchDir(pos.first, pos.second, 1, 0, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 1, 0, n, m, false);

        // 위
        WatchDir(pos.first, pos.second, 0, -1, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 0, -1, n, m, false);

        // 왼쪽
        WatchDir(pos.first, pos.second, -1, 0, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, -1, 0, n, m, false);

        // 아래
        WatchDir(pos.first, pos.second, 0, 1, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 0, 1, n, m, false);
    }
    else if(camType == 2)
    {
        // 상하
        WatchDir(pos.first, pos.second, 0, -1, n, m, true);
        WatchDir(pos.first, pos.second, 0, 1, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 0, -1, n, m, false);
        WatchDir(pos.first, pos.second, 0, 1, n, m, false);

        // 좌우
        WatchDir(pos.first, pos.second, 1, 0, n, m, true);
        WatchDir(pos.first, pos.second, -1, 0, n, m, true);
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 1, 0, n, m, false);
        WatchDir(pos.first, pos.second, -1, 0, n, m, false);
    }
    else if(camType == 3)
    {
        // 우상
        WatchDir(pos.first, pos.second, 1, 0, n, m, true); // 우
        WatchDir(pos.first, pos.second, 0, -1, n, m, true); // 상
        Search(camPos, camIndex + 1, n, m, ans);

        WatchDir(pos.first, pos.second, 1, 0, n, m, false); // 우
        WatchDir(pos.first, pos.second, -1, 0, n, m, true); // 좌
        // 상좌
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 0, -1, n, m, false); // 상
        WatchDir(pos.first, pos.second, 0, 1, n, m, true); // 하
        // 좌하
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, -1, 0, n, m, false); // 좌
        WatchDir(pos.first, pos.second, 1, 0, n, m, true); // 우
        // 하우
        Search(camPos, camIndex + 1, n, m, ans);
        WatchDir(pos.first, pos.second, 1, 0, n, m, false); // 우
        WatchDir(pos.first, pos.second, 0, 1, n, m, false); // 하
    }
    else if(camType == 4)
    {
        WatchDir(pos.first, pos.second, 0, -1, n, m, true); // 상
        WatchDir(pos.first, pos.second, -1, 0, n, m, true); // 좌
        WatchDir(pos.first, pos.second, 0, 1, n, m, true); // 하
        Search(camPos, camIndex + 1, n, m, ans); // 우 제외
        WatchDir(pos.first, pos.second, 0, -1, n, m, false); // 상
        WatchDir(pos.first, pos.second, 1, 0, n, m, true); // 우
        Search(camPos, camIndex + 1, n, m, ans); // 상 제외
        WatchDir(pos.first, pos.second, -1, 0, n, m, false); // 좌
        WatchDir(pos.first, pos.second, 0, -1, n, m, true); // 상
        Search(camPos, camIndex + 1, n, m, ans); // 좌 제외
        WatchDir(pos.first, pos.second, 0, 1, n, m, false); // 하
        WatchDir(pos.first, pos.second, -1, 0, n, m, true); // 좌
        Search(camPos, camIndex + 1, n, m, ans); // 하 제외
        WatchDir(pos.first, pos.second, 0, -1, n, m, false); // 상
        WatchDir(pos.first, pos.second, -1, 0, n, m, false); // 좌
        WatchDir(pos.first, pos.second, 1, 0, n, m, false); // 우
    }
    else if(camType == 5)
    {
        WatchDir(pos.first, pos.second, 0, -1, n, m, true);
        WatchDir(pos.first, pos.second, -1, 0, n, m, true);
        WatchDir(pos.first, pos.second, 0, 1, n, m, true);
        WatchDir(pos.first, pos.second, 1, 0, n, m, true);

        Search(camPos, camIndex + 1, n, m, ans);

        WatchDir(pos.first, pos.second, 0, -1, n, m, false);
        WatchDir(pos.first, pos.second, -1, 0, n, m, false);
        WatchDir(pos.first, pos.second, 0, 1, n, m, false);
        WatchDir(pos.first, pos.second, 1, 0, n, m, false);
    }
}


int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(status, 0, sizeof(status));

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> camPos;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
            {
                camPos.push_back({i, j});
            }
        }
    }

    int ans = INT_MAX;

    Search(camPos, 0, n, m, ans);
    cout<<ans;
}