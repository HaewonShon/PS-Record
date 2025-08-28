#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];

int Search(int n, int l, int r)
{
    long long total = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            total += board[i][j];
        }
    } 

    int ans = 10'000'000;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        long long res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res += min(mid, board[i][j]);
            }
        }

        if(res >= (total + 1) / 2)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin>>board[i][j];

    cout<<Search(n, 0, 10000000);
}