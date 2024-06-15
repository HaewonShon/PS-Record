#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    priority_queue<int> q;
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;
        q.push(-val);
    }

    int required = n-1;
    int ans = 0;

    while(required > ans)
    {
        int chainLen = -q.top();
        q.pop();

        int combined = ans + chainLen;

        if(combined == required - 1)
        {
            ans = combined;
            break;
        }
        else if(combined >= required)
        {
            ans = required;
            break;
        }
        else
        {
            ans = combined;
            --required;
        }
    }
    cout<<ans;
}
