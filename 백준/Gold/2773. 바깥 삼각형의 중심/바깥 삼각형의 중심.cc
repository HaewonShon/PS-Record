#include <bits/stdc++.h>
using namespace std;

typedef pair<float, float> Vector;

float cross(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - y1 * x2;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        Vector p[3];
        for(int i = 0; i < 3; ++i) cin>>p[i].first>>p[i].second;

        // coc 정렬
        if(cross(p[1].first - p[0].first, p[1].second - p[0].second, p[2].first - p[0].first, p[2].second - p[0].second) >= 0)
        {
            swap(p[1], p[2]);
        }

        Vector line[3]; // {a, b}, y = ax + b

        for(int i = 0; i < 3; ++i)
        {
            Vector& prev = p[(i + 3 - 1) % 3];
            Vector& curr = p[i];
            Vector& next = p[(i + 1) % 3];

            Vector currToNext = {next.first - curr.first, next.second - curr.second};
            Vector currToPrev = {prev.first - curr.first, prev.second - curr.second};

            // 90도 회전 후 curr에 더하기 -> 외부 삼각형의 두 꼭짓점
            swap(currToNext.first, currToNext.second);
            currToNext.second = -currToNext.second;
            swap(currToPrev.first, currToPrev.second);
            currToPrev.first = -currToPrev.first;

            Vector p1 = {curr.first + currToNext.first, curr.second + currToNext.second};
            Vector p2 = {curr.first + currToPrev.first, curr.second + currToPrev.second};

            Vector midPoint = {(p1.first + p2.first) / 2.f, (p1.second + p2.second) / 2.f};

            float a = (midPoint.second - curr.second) / (midPoint.first - curr.first);
            float b = curr.second - a * curr.first;

            line[i] = {a, b};
        }

        for(int i = 0; i < 3; ++i)
        {
            Vector& l1 = line[i];
            Vector& l2 = line[(i + 1) % 3];

            if(isinf(l1.first) || isinf(l2.first)) continue;

            float x = (l2.second - l1.second) / (l1.first - l2.first);
            float y = l1.first * x + l1.second;

            if(abs(x) < FLT_EPSILON) x = 0.0f;
            if(abs(y) < FLT_EPSILON) y = 0.0f;

            cout<<std::fixed<<std::setprecision(4);
            cout<<x<<" "<<y<<"\n";
            break;
        }

    } 
}