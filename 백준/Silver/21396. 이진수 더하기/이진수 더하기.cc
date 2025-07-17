#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, x;
        cin>>n>>x;

        map<int, long long> m;
        for(int i = 0; i < n; ++i)
        {
            int val;
            cin>>val;
            ++m[val];
        }

        long long ans = 0;

        for(auto p : m)
        {
            if(x == 0)
            {
                ans += p.second * (p.second-1) / 2;
            }
            else
            {
                int val = p.first;
                if(m.find(val ^ x) != m.end())
                {
                    ans += (p.second * m[val ^ x]);
                }
            }
        }
        
        if(x != 0) ans /= 2;
        cout<<ans<<"\n";
    }
}