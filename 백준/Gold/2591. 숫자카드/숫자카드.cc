#include <bits/stdc++.h>
using namespace std;

int dp[41];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    string s;
    cin>>s;
    s = " " + s;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= s.length()-1; ++i)
    {
        if(s[i] != '0') dp[i] += dp[i-1];

        if(s[i-1] != '0')
        {
            int num = (s[i-1]-'0')*10 + (s[i]-'0');
            if(num <= 34)
            {
                dp[i] += dp[i-2];
            }
        }
    }

    cout<<dp[s.length()-1]<<"\n";
}