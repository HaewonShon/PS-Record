#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<string> board(N);
    for(int i = 0; i < N; ++i) cin>>board[i];


    int ans = 0;

    //m, o 두 개 정하여 가능한 moo 수 찾기
    for(char m = 'A'; m <= 'Z'; ++m)
    {
        if(m == 'M') continue;
        for(char o = 'A'; o <= 'Z'; ++o)
        {
            if(o == 'O') continue;
            if(m == o) continue;

            int count = 0;
            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < M; ++j)
                {
                    if(board[i][j] == m)
                    {
                        if(j + 2 < m && board[i][j+1] == o && board[i][j+2] == o) ++count;
                        if(j - 2 >= 0 && board[i][j-1] == o && board[i][j-2] == o) ++count;
                        if(i + 2 < N && board[i+1][j] == o && board[i+2][j] == o) ++count;
                        if(i - 2 >= 0 && board[i-1][j] == o && board[i-2][j] == o) ++count;

                        // diagonal
                        if(j - 2 >= 0 && i + 2 < N
                            && board[i+1][j-1] == o && board[i+2][j-2] == o) ++count;
                        if(j - 2 >= 0 && i - 2 >= 0
                            && board[i-1][j-1] == o && board[i-2][j-2] == o) ++count;
                        if(j + 2 < m && i + 2 < N
                            && board[i+1][j+1] == o && board[i+2][j+2] == o) ++count;
                        if(j + 2 < m && i - 2 >= 0
                            && board[i-1][j+1] == o && board[i-2][j+2] == o) ++count;
                    }
                }
            }
            ans = max(ans, count);
        }
    }
    cout<<ans;
}