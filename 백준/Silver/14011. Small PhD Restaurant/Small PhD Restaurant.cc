#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) cin>>v[i].first;
    for(int i = 0; i < n; ++i) cin>>v[i].second;

    sort(v.begin(), v.end(), [](auto& p1, auto& p2){
        if(p1.first == p2.first) return p1.first < p2.first;
        return p1.first < p2.first;
    });

    for(auto& p : v)
    {
        if(p.second - p.first < 0) continue;
        if(p.first > m) break;

        m += p.second - p.first;
    }

    cout<<m;
}
    