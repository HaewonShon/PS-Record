#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> classes(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>classes[i].first>>classes[i].second;
    }
    sort(classes.begin(), classes.end(), [](auto p1, auto p2){return p1.first < p2.first; });
    
    priority_queue<int, vector<int>, std::greater<int>> currentClasses;
    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        while(!currentClasses.empty() && currentClasses.top() <= classes[i].first)
        {
            currentClasses.pop();
        }

        currentClasses.push(classes[i].second);
        ans = max(ans, (int)currentClasses.size());
    }
    cout<<ans;
}