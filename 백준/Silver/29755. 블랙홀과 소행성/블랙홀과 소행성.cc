#include <bits/stdc++.h>
using namespace std;

int GetNearestDiff(const vector<int>& b, int a)
{
    if(b.size() == 1)
    {
        return abs(b[0] - a);
    }

    int l = 0;
    int r = b.size() - 1;

    int index = -1;
    while(l <= r)
    {
        int mid = l + (r-l) / 2;
        index = mid;
        if(b[mid] < a)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    int res = abs(a - b[index]);
    if(index > 0) res = min(res, abs(a - b[index-1]));
    if(index < b.size()-1) res = min(res, abs(a - b[index+1]));

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> b(n);
    for(int i = 0; i < n; ++i) cin>>b[i];

    sort(b.begin(), b.end());

    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
        int a, w;
        cin>>a>>w;

        int dist = GetNearestDiff(b, a);
        ans = max(ans, dist * w);
    }

    cout<<ans;
}