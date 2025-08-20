#include <bits/stdc++.h>
using namespace std;

int maxProfit[1'500'001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(maxProfit, 0, sizeof(maxProfit));

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 1; i <= n; ++i)
    {
        maxProfit[i] = max(maxProfit[i-1], maxProfit[i]);

        int days, profit;
        cin>>days>>profit;

        int endDay = i + days - 1;
        if(endDay <= n)
        {
            maxProfit[endDay] = max(maxProfit[endDay], maxProfit[i-1] + profit);
        }
    }

    int ans = 0;
    for(int i = max(1, n - 50); i <= n; ++i)
    {
        ans = max(ans, maxProfit[i]);
    }
    cout<<ans;
}