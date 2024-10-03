#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    priority_queue<int> q;

    int current = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;

        current += val;
        q.push(val);

        if(current >= m)
        {
            current -= q.top()*2;
            q.pop();
            ++ans;
        }
    }
    cout<<ans;
}
