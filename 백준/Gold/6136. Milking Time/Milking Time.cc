#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, r;
    cin>>n>>m>>r;

    vector<pair<pair<int, int>, int>> v(m); // {{end, start}, efficiency}
    for(int i = 0; i < m; ++i)
    {
        cin>>v[i].first.second>>v[i].first.first>>v[i].second;
    }

    sort(v.begin(), v.end());

    vector<pair<int, int>> timeline; // {endtime, amount}
    timeline.push_back({0, 0});

    for(int i = 0; i < m; ++i)
    {
        int startTime = max(0, v[i].first.second - r);
        for(int j = timeline.size()-1; j >= 0; --j)
        {
            if(timeline[j].first <= startTime)
            {
                int amount = timeline[j].second + v[i].second;
                if(amount > timeline.back().second)
                {
                    if(timeline.back().first == v[i].first.first)
                    {
                        timeline.back().second = amount;
                    }
                    else
                    {
                        timeline.push_back({v[i].first.first, amount});
                    }
                }   
                break;             
            }
        }    
    }
    cout<<timeline.back().second;
}