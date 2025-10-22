#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    sort(v.rbegin(), v.rend());

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for(int time = 1; time <= n; ++time)
    {
        while(!pq.empty() && pq.top() < time)
        {
            pq.pop();
        }
        pq.push(time + v[time - 1] - 1);
        ans = max(ans, (int)pq.size());
    }
    cout<<ans;
}   