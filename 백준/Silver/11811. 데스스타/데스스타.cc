#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>board[i][j];
        }
    }

    vector<int> ans(n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            ans[i] |= board[i][j];
            ans[j] |= board[i][j];
        }
    }

    for(int i : ans)
    {
        cout<<i<<" ";
    }
}