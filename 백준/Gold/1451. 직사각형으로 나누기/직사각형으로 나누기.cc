#include <bits/stdc++.h>
using namespace std;

unsigned long long board[50][50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; ++i)
    {
        string s;
        cin>>s;

        for(int j = 0; j < m; ++j)
        {
            board[i][j] = s[j] - '0';
        }
    }

    for(int i = 1; i < n; ++i)
    {
        board[i][0] += board[i-1][0];
    }
    for(int j = 1; j < m; ++j)
    {
        board[0][j] += board[0][j-1];
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
        }
    }

    unsigned long long ans = 0;
    // 1. 가로로 긴 직사각형 3개
    for(int h1 = 0; h1 < n-2; ++h1)
    {
        for(int h2 = h1 + 1; h2 < n-1; ++h2)
        {
            ans = max(ans, board[h1][m-1] * (board[h2][m-1] - board[h1][m-1]) * (board[n-1][m-1] - board[h2][m-1]));
        }
    }

    // 2. 가로로 긴 직사각형 + 남은 공간을 세로로 양분
    // 긴게 위
    for(int h = 0; h < n-1; ++h)
    {
        for(int w = 0; w < m-1; ++w)
        {
            ans = max(ans, board[h][m-1] * (board[n-1][w] - board[h][w]) * (board[n-1][m-1] - board[n-1][w] - board[h][m-1] + board[h][w]));
        }
    }
    // 긴게 아래
    for(int h = 1; h <= n-1; ++h)
    {
        for(int w = 0; w < m-1; ++w)
        {
            ans = max(ans, board[h-1][w] * (board[h-1][m-1] - board[h-1][w]) * (board[n-1][m-1] - board[h-1][m-1]));
        }
    }

    // 3. 세로로 긴 직사각형 3개
    for(int w1 = 0; w1 < m-2; ++w1)
    {
        for(int w2 = w1 + 1; w2 < m-1; ++w2)
        {
            ans = max(ans, board[n-1][w1] * (board[n-1][w2] - board[n-1][w1]) * (board[n-1][m-1] - board[n-1][w2]));
        }
    }

    // 4. 세로 긴 직사각형 + 남은 공간 가로 양분
    // 긴게 왼쪽
    for(int w = 0; w < m-1; ++w)
    {
        for(int h = 0; h < n-1; ++h)
        {
            ans = max(ans, board[n-1][w] * (board[h][m-1] - board[h][w]) * (board[n-1][m-1] - board[n-1][w] - board[h][m-1] + board[h][w]));
        }
    }
    // 긴게 오른쪽
    for(int w = 1; w <= m-1; ++w)
    {
        for(int h = 0; h < n-1; ++h)
        {
            ans = max(ans, board[h][w-1] * (board[n-1][w-1] - board[h][w-1]) * (board[n-1][m-1] - board[n-1][w-1]));
        }
    }

    cout<<ans;
}