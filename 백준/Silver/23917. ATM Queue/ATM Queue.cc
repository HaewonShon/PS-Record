#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test = 1; test <= t; ++test)
    {
        int n, x;
        cin>>n>>x;

        vector<int> amount(n+1);
        for(int i = 1; i <= n; ++i) cin>>amount[i];

        queue<int> q;
        for(int i = 1; i <= n; ++i) q.push(i);

        cout<<"Case #"<<test<<": ";
        while(!q.empty())
        {
            int next = q.front();
            q.pop();

            amount[next] = max(amount[next] - x, 0);
            if(amount[next] > 0) q.push(next);
            else cout<<next<<" ";
        }

        cout<<"\n";
    }
}