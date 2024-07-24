#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;

    while(cin>>n>>m)
    {
        if(n == 0 && m == 0) break;

        unordered_map<int, int> info;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int player;
                cin>>player;
                ++info[player];
            }
        }

        vector<pair<int, int>> v;
        for(auto& p : info)
        {
            v.push_back(p);
        }

        sort(v.begin(), v.end(), [](auto& p1, auto& p2){
            if(p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        });

        for(int i = 1; i < v.size(); ++i)
        {
            if(v[i].second != v[1].second)
            {
                break;
            }
            cout<<v[i].first<<" ";
        }
        cout<<"\n";
    }
}