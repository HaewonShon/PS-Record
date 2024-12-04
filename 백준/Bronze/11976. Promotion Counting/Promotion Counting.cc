#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<pair<int, int>> v(4);
    for(int i = 0; i < 4; ++i)
    {
        cin>>v[i].first>>v[i].second;
    }

    int ans[3];

    for(int i = 3; i > 0; --i)
    {
        ans[i-1] = v[i].second - v[i].first;
        v[i-1].first -= ans[i-1];
    }

    cout<<ans[0]<<"\n"<<ans[1]<<"\n"<<ans[2];
}