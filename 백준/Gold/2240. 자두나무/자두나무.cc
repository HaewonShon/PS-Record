#include <bits/stdc++.h>
using namespace std;

int maxProfit[1001][31];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(maxProfit, 0, sizeof(maxProfit));

    int t, w;
    cin>>t>>w;

    for(int i = 1; i <= t; ++i)
    {
        int input;
        cin>>input;

        for(int j = 0; j <= w; ++j)
        {
            maxProfit[i][j] = max(maxProfit[i-1][j], 
                (j > 0 ? maxProfit[i-1][j-1] : 0));
            
            if(input % 2 == (j + 1) % 2) ++maxProfit[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i <= w; ++i)
    {
        ans = max(ans, maxProfit[t][i]);
    }

    cout<<ans;
}