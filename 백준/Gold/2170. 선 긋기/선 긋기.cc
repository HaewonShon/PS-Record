#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> lines(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>lines[i].first>>lines[i].second;
    }

    sort(lines.begin(), lines.end(), [](auto p1, auto p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        else return p1.first < p2.first;
    });

    int start = lines[0].first;
    int end = lines[0].second;

    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        if(lines[i].first > end)
        {
            ans += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
        else
        {
            end = max(end, lines[i].second);
        }
    }

    ans += end - start;
    cout<<ans;
}