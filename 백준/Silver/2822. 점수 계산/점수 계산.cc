#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    vector<pair<int, int>> v(8);
    for(int i = 0; i < 8; ++i)
    {
        cin>>v[i].first;
        v[i].second = i+1;
    }

    sort(v.rbegin(), v.rend());

    int total = 0;
    vector<int> ans(5);
    for(int i = 0; i < 5; ++i)
    {
        total += v[i].first;
        ans[i] = v[i].second;
    }

    sort(ans.begin(), ans.end());

    cout<<total<<"\n";
    for(int i : ans)
    {
        cout<<i<<" ";
    }
}
