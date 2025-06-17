#include <bits/stdc++.h>
using namespace std;

struct Quad
{
    int x[4];
    int y[4];
};

int cases[6][4] = {{0, 1, 2, 3},
                    {0, 1, 3, 2},
                    {0, 2, 1, 3},
                    {0, 2, 3, 1},
                    {0, 3, 1, 2},
                    {0, 3, 2, 1}};

int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool IsAInsideB(const Quad& A, const Quad& B)
{
    for(int c = 0; c < 6; ++c) // for each case
    {
        bool inside = true;

        for(int a = 0; a < 4 && inside; ++a) // for each vertex in A
        {
            for(int b = 0; b < 4; ++b)
            {
                if(CCW(B.x[cases[c][b]], B.y[cases[c][b]], B.x[cases[c][(b+1)%4]], B.y[cases[c][(b+1)%4]], A.x[a], A.y[a]) > 0)
                {
                    inside = false;
                    break;
                }
            }
        }

        if(inside) return true;
    }


    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<Quad> quad(n);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin>>quad[i].x[j]>>quad[i].y[j];
        }
    }

    int ans = 1;
    for(int i = 0; i < n; ++i)
    {
        int res = 1;
        for(int j = 0; j < n; ++j)
        {
            if(i == j) continue;

            if(IsAInsideB(quad[j], quad[i])) ++res;
        }
        ans = max(ans, res);
    }
    
    cout<<ans;
}