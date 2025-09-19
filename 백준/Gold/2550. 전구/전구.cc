#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;

    int n;
    cin>>n;

    vector<int> posToSwitch(n+1);
    vector<int> bulbToPos(n+1);

    for(int i = 1; i <= n; ++i)
    {
        cin>>posToSwitch[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        int bulb;
        cin>>bulb;
        bulbToPos[bulb] = i;
    }

    vector<int> sequence(n+1);
    for(int i = 1; i <= n; ++i)
    {
        sequence[i] = bulbToPos[posToSwitch[i]];
    }

    for(int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            if(sequence[j] < sequence[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }


    int lastIndex = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dp[i] > dp[lastIndex])
        {
            lastIndex = i;
        }
    }
    
    vector<int> res;
    res.push_back(lastIndex);
    int len = dp[lastIndex] - 1;
    for(int i = lastIndex; i >= 1; --i)
    {
        if(sequence[i] < sequence[res.back()] && dp[i] == len)
        {
            res.push_back(i);
            len--;
        }
    }

    sort(res.begin(), res.end(), [posToSwitch](int i1, int i2){ return posToSwitch[i1] < posToSwitch[i2]; });

    cout<<res.size()<<"\n";
    for(int val : res)
    {
        cout<<posToSwitch[val]<<" ";
    }   
}