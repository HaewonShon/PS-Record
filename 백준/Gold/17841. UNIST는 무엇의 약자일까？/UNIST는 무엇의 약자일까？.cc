#include <bits/stdc++.h>
using namespace std;

int dp[100001][6]; // i번째에서 j로 끝나는 경우의 수
const string target = "UNIST";
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    memset(dp, 0, sizeof(dp));

    vector<string> v(n);
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin>>s;

        dp[i][0] = 1;

        for(int j = 1; j <= 5; ++j)
        {
            dp[i][j] += dp[i-1][j]; // j를 사용하지 않는 경우
            dp[i][j] %= MOD;

            if(s[0] == target[j-1])
            {
                for(int offset = 0; offset < s.length() && offset + j <= 5; ++offset)
                {
                    if(s[offset] != target[j+offset-1]) break;

                    dp[i][j+offset] += dp[i-1][j-1];
                    dp[i][j+offset] %= MOD;
                }
            }
        }
    }

    cout<<dp[n][5];
}
