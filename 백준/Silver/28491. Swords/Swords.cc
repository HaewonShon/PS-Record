#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int maxDef = 0;
    for(int i = n-1; i >= 0; --i)
    {
        if(v[i].second > maxDef)
        {
            ++ans;
            maxDef = v[i].second;
        }
    }

    cout<<ans;
}