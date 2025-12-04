#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    long long res = 0;
    for(int i = 0; i < n/2; ++i)
    {
        int& a = arr[i];
        int& b = arr[n-i-1];

        int diff = abs(a - b);
        res += diff / k;
        diff -= (k * (diff / k));

        res += min(diff, 1 + k - diff);
    }
    cout<<res;
}   