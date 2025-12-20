#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i < n; ++i)
    {
        cin>>b[i];
    }

    int totalDiff = 0;
    for(int i = 0; i < n; ++i)
    {
        totalDiff += abs(a[i]-b[i]);
    }
    cout<<totalDiff/2;
}   