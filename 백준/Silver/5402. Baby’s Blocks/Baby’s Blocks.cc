#include <bits/stdc++.h>
using namespace std;

long long factorial[20];

long long GetFactorial(long long val)
{
    if(val == 1) return 1;

    if(factorial[val] != -1) return factorial[val];
    return factorial[val] = val * GetFactorial(val-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(factorial, -1, sizeof(factorial));

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        
        vector<int> appearence(26, 0);
        for(char c : s)
        {
            ++appearence[c - 'A'];
        }

        long long ans = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < 26; ++j)
            {
                if(s[i] != 'A' + j)
                {
                    if(appearence[j] == 0) continue;
                    long long divider = (appearence[j] == 1) ? 1 : GetFactorial(appearence[j] - 1);

                    for(int k = 0; k < 26; ++k)
                    {
                        if(j == k) continue;
                        if(appearence[k] <= 1) continue;
                        divider *= GetFactorial(appearence[k]);
                    }
                    ans += GetFactorial(n-i-1) / divider;
                }
                else
                {
                    --appearence[j];
                    break;
                }
            }
        }

        cout<<ans<<"\n";
    }
}