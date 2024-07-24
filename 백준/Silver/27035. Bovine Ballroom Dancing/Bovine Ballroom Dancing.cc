#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += abs(a[i] - b[i]);
    }
    cout<<ans;
}