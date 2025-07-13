#include <bits/stdc++.h>
using namespace std;

int board[501][501];
const int DEATH_ZONE = -1e9;
const int VISITED = 1e7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));

    int dangerZoneCount;
    cin>>dangerZoneCount;

    while(dangerZoneCount-- > 0)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        for(int i = min(y1, y2); i <= max(y1, y2); ++i)
        {
            for(int j = min(x1, x2); j <= max(x1, x2); ++j)
            {
                board[i][j] = -1;
            }
        }
    }

    int deathZoneCount;
    cin>>deathZoneCount;

    while(deathZoneCount-- > 0)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        for(int i = min(y1, y2); i <= max(y1, y2); ++i)
        {
            for(int j = min(x1, x2); j <= max(x1, x2); ++j)
            {
                board[i][j] = DEATH_ZONE;
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    board[0][0] = VISITED;

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1, 1};

    while(!pq.empty())
    {
        auto next = pq.top();
        pq.pop();

        auto pos = next.second;

        if(pos.first == 500 && pos.second == 500)
        {
            cout<<abs(next.first);
            return 0;
        }

        for(int i = 0; i < 4; ++i)
        {
            auto movedPos = pos;
            movedPos.first += xOffset[i];
            movedPos.second += yOffset[i];
            
            if(movedPos.first < 0 || movedPos.first > 500 || movedPos.second < 0 || movedPos.second > 500) continue;

            int penalty = board[movedPos.second][movedPos.first];
            if(penalty == DEATH_ZONE || penalty == VISITED) continue;
            else
            {
                pq.push({next.first + penalty, movedPos});
                board[movedPos.second][movedPos.first] = VISITED;
            }
        }
    }

    // failed to reach goal
    cout<<-1;
}