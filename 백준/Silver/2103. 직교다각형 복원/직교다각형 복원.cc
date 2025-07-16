#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<Point> xSort(n);
    vector<Point> ySort(n);
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin>>x>>y;
        
        xSort[i] = {x, y};
        ySort[i] = {y, x};
    }
    
    sort(xSort.begin(), xSort.end());
    sort(ySort.begin(), ySort.end());

    int ans = 0;
    for(int i = 1; i < n; i += 2)
    {
        ans += xSort[i].second - xSort[i-1].second;
        ans += ySort[i].second - ySort[i-1].second;
    }
    cout<<ans;
}