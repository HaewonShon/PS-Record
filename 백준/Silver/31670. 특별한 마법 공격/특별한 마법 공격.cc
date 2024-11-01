#include <bits/stdc++.h>
using namespace std;

long dp[100001]; // i가 사는 최소 비용

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> resist(n+1);

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; ++i)
    {
        cin>>resist[i];
    }

    dp[1] = 0;    
    dp[2] = resist[1];

    for(int i = 3; i <= n; ++i)
    {
        dp[i] = min(dp[i-3] + resist[i-2] + resist[i-1], dp[i-2] + resist[i-1]);
    }
    cout<<min(dp[n-1] + resist[n], dp[n]);
}