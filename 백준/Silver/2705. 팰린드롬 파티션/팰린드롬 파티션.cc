#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 4;
    dp[5] = 4;

    for(int i = 6; i <= 1000; ++i)
    {
        if(i % 2)
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = dp[i-1] + dp[i/2];
        }
    }

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        cout<<dp[n]<<"\n";
    }
}