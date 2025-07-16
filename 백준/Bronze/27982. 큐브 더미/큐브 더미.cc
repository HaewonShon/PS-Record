#include <bits/stdc++.h>
using namespace std;

char board[6][6][6];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));

    int n, m;
    cin>>n>>m;

    while(m--)
    {
        int i, j, k;
        cin>>i>>j>>k;
        board[i][j][k] = 1;
    }

    int ans = 0;

    for(int i = 2; i <= n-1; ++i)
        for(int j = 2; j <= n-1; ++j)
            for(int k = 2; k <= n-1; ++k)
            {
                if(board[i][j][k] == 1
                && board[i-1][j][k] == 1
                && board[i+1][j][k] == 1
                && board[i][j-1][k] == 1
                && board[i][j+1][k] == 1
                && board[i][j][k-1] == 1
                && board[i][j][k+1] == 1)
                    ++ans;
            }
    cout<<ans;
}