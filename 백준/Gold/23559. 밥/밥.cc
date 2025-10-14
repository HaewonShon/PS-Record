#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), [](auto& p1, auto& p2){
        return p1.first - p1.second > p2.first - p2.second;
    });

    int foodACount = (x - n * 1000) / 4000;
    long long ans = 0;
    for(auto p : v)
    {
        if(foodACount > 0 && p.first > p.second)
        {
            ans += p.first;
            --foodACount;
        }
        else
        {
            ans += p.second;
        }
    }
    cout<<ans;
}   