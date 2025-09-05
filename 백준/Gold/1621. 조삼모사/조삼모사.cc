#include <bits/stdc++.h>
using namespace std;

int dp[1'000'001][2]; // {res, k}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n;
    cin>>n;

    int k, c;
    cin>>k>>c;

    vector<int> banana(n+1);
    for(int i = 1; i <= n; ++i) cin>>banana[i];

    for(int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i-1][0] + banana[i];
        dp[i][1] = dp[i-1][1];
        
        if(i-k >= 0 && dp[i-k][0] + c < dp[i][0])
        {
            dp[i][0] = dp[i-k][0] + c;
            dp[i][1] = dp[i-k][1] + 1;
        }
    }

    cout<<dp[n][0]<<"\n"<<dp[n][1]<<"\n";

    stack<int> pos;

    int index = n;
    while(index > 0)
    {
        if(dp[index][1] == dp[index-k][1] + 1 && dp[index][0] == dp[index-k][0] + c)
        {
            index = index - k;
            pos.push(index+1);
            if(dp[index][1] == 0) break;
        }
        else
        {
            --index;
        }
    }

    while(!pos.empty())
    {
        cout<<pos.top()<<" ";
        pos.pop();
    }
}