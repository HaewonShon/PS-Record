#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int ans = 0;

    int currBegin, currEnd;
    cin>>currBegin>>currEnd;


    for(int i = 1; i < n; ++i)
    {
        int x, y;
        cin>>x>>y;

        // 이어붙일 수 있는 경우
        if(x <= currEnd)
        {
            currEnd = max(currEnd, y);
        }
        else
        {
            ans += currEnd - currBegin;
            currBegin = x;
            currEnd = y;
        }
    }

    ans += currEnd - currBegin;
    cout<<ans;
}