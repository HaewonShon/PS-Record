#include <bits/stdc++.h>
using namespace std;

string triangle[2] = {" /\\ ", "/__\\"};
char board[2048][4096];

void Draw(int x, int y, int size)
{
    if(size == 2)
    {
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                board[y + i][2 * x + j] = triangle[i][j];
            }
        }
    }
    else
    {
        Draw(x + size / 4, y, size / 2);
        Draw(x, y + size / 2, size / 2);
        Draw(x + size / 2, y + size / 2, size / 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin>>n)
    {
        if(n == 0) break;

        memset(board, ' ', sizeof(board));

        int size = 1 << n;
        Draw(0, 0, size);

        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size + i + 1; ++j)
            {
                cout<<board[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}