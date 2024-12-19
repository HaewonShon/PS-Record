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

        vector<pair<int, int>> amount(n+1);
        for(int i = 1; i <= n; ++i)
        {
            int a;
            cin>>a;

            amount[i] = {(a + x - 1) / x, i};
        }

        sort(amount.begin(), amount.end());

        queue<int> q;
        for(int i = 1; i <= n; ++i) q.push(i);

        cout<<"Case #"<<test<<": ";
        for(int i = 1; i <= n; ++i)
        {
            cout<<amount[i].second<<" ";
        }

        cout<<"\n";
    }
}