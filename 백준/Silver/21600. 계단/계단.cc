#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) cin>>v[i];

    dp[0] = 1;

    for(int i = 1; i < n; ++i)
    {
        if(dp[i-1] < v[i]) dp[i] = dp[i-1] + 1;
        else dp[i] = min(v[i], dp[i-1]);
    }

    cout<<*max_element(dp.begin(), dp.end());
}