#include <bits/stdc++.h>
using namespace std;

 int board[100][100];
 bool isFallen[100][100];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, r;
    cin>>n>>m>>r;

    memset(isFallen, false, sizeof(isFallen));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
        }
    }

    int xOffset[4] = {1, -1, 0, 0};
    int yOffset[4] = {0, 0, 1, -1};

    int score = 0;

    while(r--)
    {
        // attacker
        int x, y;
        char d;

        cin>>y>>x>>d;
        --x;
        --y;

        if(!isFallen[y][x])
        {
            int dir;
            switch(d)
            {
                case 'E': dir = 0; break;
                case 'W': dir = 1; break;
                case 'S': dir = 2; break;
                case 'N': dir = 3; break;
            }

            int range = board[y][x];

            for(int i = 0; i < range; ++i)
            {
                int targetX = x + i * xOffset[dir];
                int targetY = y + i * yOffset[dir];

                if(targetX >= 0 && targetX < m && targetY >= 0 && targetY < n)
                {
                    if(!isFallen[targetY][targetX])
                    {
                        ++score;
                        isFallen[targetY][targetX] = true;
                        range = max(range, i + board[targetY][targetX]);
                    }
                }
                else
                {
                    break;
                }
            }
        }

        // defender
        cin>>y>>x;
        --x;
        --y;

        if(isFallen[y][x])
        {
            isFallen[y][x] = false;
        }
    }

    cout<<score<<"\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout<<(isFallen[i][j] ? 'F' : 'S')<<" ";
        }
        cout<<"\n";
    }
}