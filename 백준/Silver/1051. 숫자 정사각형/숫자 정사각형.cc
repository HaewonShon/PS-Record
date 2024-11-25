#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> board(n);
    for(int i = 0; i < n; ++i) cin>>board[i];

    int size = min(n, m);

    while(size > 0)
    {
        for(int i = 0; i + size - 1 < n; ++i)
        {
            for(int j = 0; j + size - 1 < m; ++j)
            {
                if(board[i][j] == board[i][j+size-1]
                && board[i][j] == board[i+size-1][j]
                && board[i][j] == board[i+size-1][j+size-1])
                {
                    cout<<size*size;
                    return 0;
                }
            }
        }
        --size;
    }
}