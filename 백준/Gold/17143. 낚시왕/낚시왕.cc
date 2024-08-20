#include <bits/stdc++.h>
using namespace std;

struct Shark
{
    int r, c;
    int speed, dir, size;
    bool isAlive = true;
};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int R, C, m;
    cin>>R>>C>>m;

    vector<vector<int>> board(R, vector<int>(C, -1)); // 상어의 index 저장
    vector<Shark> sharks;

    for(int i = 0; i < m; ++i)
    {
        int r, c, s, d, z;
        cin>>r>>c>>s>>d>>z;
        sharks.push_back({r-1, c-1, s, d, z});
        board[r-1][c-1] = i;
    }

    int ans = 0;
    for(int x = 0; x < C; ++x)
    {
        // 상어 잡기
        for(int y = 0; y < R; ++y)
        {
            if(board[y][x] == -1) continue;

            ans += sharks[board[y][x]].size;
            sharks[board[y][x]].isAlive = false;
            board[y][x] = -1;
            break;
        }

        vector<vector<int>> newBoard(R, vector<int>(C, -1));

        // 상어 이동
        for(int sharkNum = 0; sharkNum < m; ++sharkNum)
        {
            Shark& shark = sharks[sharkNum];
            if(!shark.isAlive) continue;

            int moveDist = (shark.dir <= 2) ? shark.speed % (2 * (R-1)) : shark.speed % (2 * (C-1));

            if(shark.dir == 1 || shark.dir == 2) // 위 or 아래
            { 
                int turn1 = (shark.dir == 1) ? shark.r : (R-1) - shark.r; // 첫 방향전환까지 남으 ㄴ거리
                int turn2 = turn1 + (R-1); // 두번째 방향전환까지 남은 거리

                if(moveDist <= turn1)
                {
                    shark.r = (shark.dir == 1) ? shark.r - moveDist : shark.r + moveDist;
                }
                else if(moveDist <= turn2)
                {
                    shark.r = (shark.dir == 1) ? moveDist - turn1 : (R-1) - (moveDist - turn1);
                    shark.dir = (shark.dir == 1) ? 2 : 1;
                }
                else
                {
                    shark.r = (shark.dir == 1) ? (R-1) - (moveDist - turn2) : (moveDist - turn2);
                }
            }
            else
            {
                int turn1 = (shark.dir == 4) ? shark.c : (C-1) - shark.c; // 첫 방향전환까지 남으 ㄴ거리
                int turn2 = turn1 + (C-1); // 두번째 방향전환까지 남은 거리

                if(moveDist <= turn1)
                {
                    shark.c = (shark.dir == 4) ? shark.c - moveDist : shark.c + moveDist;
                }
                else if(moveDist <= turn2)
                {
                    shark.c = (shark.dir == 4) ? moveDist - turn1 : (C-1) - (moveDist - turn1);
                    shark.dir = (shark.dir == 4) ? 3 : 4;
                }
                else
                {
                    shark.c = (shark.dir == 4) ? (C-1) - (moveDist - turn2) : (moveDist - turn2);
                }
            }

            if(newBoard[shark.r][shark.c] == -1)
            {
                newBoard[shark.r][shark.c] = sharkNum;
            }
            else
            {
                Shark& shark2 = sharks[newBoard[shark.r][shark.c]];
                if(shark.size < shark2.size)
                {
                    shark.isAlive = false;
                }
                else
                {
                    shark2.isAlive = false;
                    newBoard[shark.r][shark.c] = sharkNum;
                }
            }
        }

        board = std::move(newBoard);
    }

    cout<<ans;
}
