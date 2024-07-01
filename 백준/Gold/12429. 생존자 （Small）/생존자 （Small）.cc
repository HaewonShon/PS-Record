#include <bits/stdc++.h>
using namespace std;

void Search(vector<pair<int, int>>& v, int current, int& ans)
{
    ans = max(ans, current);

    for(auto& p : v)
    {
        if(current <= p.first) // 먹을 수 있는 식량
        {
            int temp = p.first;
            p.first = -1;
            current += p.second;

            Search(v, current, ans);

            p.first = temp;
            current -= p.second;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    for(int test = 1; test <= t; ++test)
    {
        int n;
        cin>>n;

        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin>>v[i].first>>v[i].second;
        }
        
        int ans = 0;
        Search(v, 0, ans);
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
}   