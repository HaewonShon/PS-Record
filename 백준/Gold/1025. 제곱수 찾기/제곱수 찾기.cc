#include <bits/stdc++.h>
using namespace std;

int GetMaxSquareNum(const vector<string>& v, int n, int m,
                int x, int y, int xDiff, int yDiff)
{
    if(xDiff == 0 && yDiff == 0) return -1;

    string res;
    int maxSquareNum = -1;

    while(y < n && y >= 0 && x < m && x >= 0)
    {
        res += v[y][x];
        y += yDiff;
        x += xDiff;

        int intRes = atoi(res.c_str());
        int sqrtRes = (int)sqrt(intRes);

        if(sqrtRes * sqrtRes == intRes) maxSquareNum = intRes;
    }

    return maxSquareNum;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    int ans = -1;

    for(int yDiff = -n; yDiff <= n; ++yDiff)
    {
        for(int xDiff = -m; xDiff <= m; ++xDiff)
        {
            for(int y = 0; y < n; ++y)
            {
                for(int x = 0; x < m; ++x)
                {
                    ans = max(ans, GetMaxSquareNum(v, n, m, x, y, xDiff, yDiff));
                }
            }
        }
    }

    cout<<ans;
}