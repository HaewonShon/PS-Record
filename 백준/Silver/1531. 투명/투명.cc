#include <bits/stdc++.h>
using namespace std;

int board[101][101];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    memset(board, 0, sizeof(board));
    for(int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        for(int j = y1; j <= y2; ++j)
        {
            for(int k = x1; k <= x2; ++k)
            {
                ++board[j][k];
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 100; ++i)
    {
        for(int j = 1; j <= 100; ++j)
        {
            if(board[i][j] > m) ++ans;
        }
    }
    cout<<ans;
}
