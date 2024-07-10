#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    priority_queue<int> q;
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;
        q.push(val);
    }

    int ans = 0;
    while(!q.empty())
    {
        int top1 = q.top();
        q.pop();

        if(q.empty())
        {
            ans += top1;
        }
        else
        {
            int top2 = q.top();
            q.pop();

            ans += top2;
            top1 -= top2;
            if(top1 > 0) q.push(top1);
            if(ans > 1440) break;
        }        
    }
    
    if(ans > 1440) cout<<"-1";
    else cout<<ans;
}