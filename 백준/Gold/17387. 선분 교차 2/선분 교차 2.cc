#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int CCW(Point& A, Point& B, Point C)
{
    long long res = (A.x * B.y + B.x * C.y + C.x * A.y) - (B.x * A.y + C.x * B.y + A.x * C.y);
    if(res == 0) return 0;
    else return (res > 0) ? -1 : 1;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    Point points[4];
    for(int i = 0; i < 4; ++i)
    {
        cin>>points[i].x>>points[i].y;
    }

    if(points[0].x > points[1].x) swap(points[0], points[1]);
    if(points[2].x > points[3].x) swap(points[2], points[3]);

    int res1 = CCW(points[0], points[1], points[2]) * CCW(points[0], points[1], points[3]);
    int res2 = CCW(points[2], points[3], points[0]) * CCW(points[2], points[3], points[1]);

    if(res1 > 0 || res2 > 0) cout<<"0";
    else if(res1 == 0 && res2 == 0)
    {
        if(points[0].x > points[3].x || points[1].x < points[2].x) cout<<"0";
        else if(min(points[0].y, points[1].y) > max(points[2].y, points[3].y)
            || min(points[2].y, points[3].y) > max(points[0].y, points[1].y)) cout<<"0";
        else cout<<"1";
    }
    else cout<<"1";
}