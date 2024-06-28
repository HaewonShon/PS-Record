#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int tc = 1;

    while(n != 0)
    {
        vector<pair<string, string>> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin>>v[i].first>>v[i].second;
        }

        vector<int> next(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(v[i].second == v[j].first)
                {
                    next[i] = j;
                    break;
                }
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                ++ans;
                int curr = i;
                while(!visited[curr])
                {
                    visited[curr] = true;
                    curr = next[curr];
                }
            }
        }

        cout<<tc++<<" "<<ans<<"\n";
        cin>>n;
    }
}   