#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> board(n);
    vector<string> expect(n);
    for(int i = 0; i < n; ++i) cin>>board[i];
    for(int i = 0; i < n; ++i) cin>>expect[i];

    int ans = 0;
    for(int i = 0; i < n-2; ++i)
    {
        for(int j = 0; j < m-2; ++j)
        {
            if(board[i][j] != expect[i][j])
            {
                ++ans;
                for(int y = 0; y < 3; ++y)
                {
                    for(int x = 0; x < 3; ++x)
                    {
                        board[i+y][j+x] = (board[i+y][j+x] == '0') ? '1' : '0';
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] != expect[i][j])
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<ans;
}