#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001]; // a[i], b[j]까지 진행했을 때 최대값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int a, b, c;
    string s1, s2;
    cin>>a>>b>>c>>s1>>s2;
    int s1Len = s1.length(), s2Len = s2.length();

    dp[0][0] = 0;
    for(int i = 0; i <= s1Len; ++i) dp[i][0] = i * b;
    for(int i = 0; i <= s2Len; ++i) dp[0][i] = i * b;


    for(int i = 1; i <= s1Len; ++i)
    {
        for(int j = 1; j <= s2Len; ++j)
        {
            dp[i][j] = max(max(dp[i-1][j] + b, dp[i][j-1] + b), dp[i-1][j-1] + ((s1[i-1] == s2[j-1]) ? a : c));
        }
    }

    cout<<dp[s1Len][s2Len];
}