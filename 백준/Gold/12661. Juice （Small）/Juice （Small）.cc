#include <bits/stdc++.h>
using namespace std;

int maxVal[1<<10][3]; // 사람을 골랐을 때 a, b, c의 최댓값. <=10000을 만족한다면 해당 사람들을 모두 만족시킴

int GetBitCount(int val)
{
    int res = 0;
    while(val > 0)
    {
        if(val & 1) ++res;
        val >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin>>t;

    for(int test = 1; test <= t; ++test)
    {
        int n;
        cin>>n;

        memset(maxVal, 0, sizeof(maxVal));

        for(int i = 0; i < n; ++i)
        {
            int bit = 1 << i;
            cin>>maxVal[bit][0]>>maxVal[bit][1]>>maxVal[bit][2];

            for(int j = 1; j <= bit; ++j)
            {
                maxVal[bit | j][0] = max(maxVal[bit][0], maxVal[j][0]);
                maxVal[bit | j][1] = max(maxVal[bit][1], maxVal[j][1]);
                maxVal[bit | j][2] = max(maxVal[bit][2], maxVal[j][2]);
            }
        }

        int ans = 0;
        for(int i = 1; i < (1<<n); ++i)
        {
            if((maxVal[i][0] + maxVal[i][1] + maxVal[i][2]) <= 10000)
            {
                ans = max(ans, GetBitCount(i));
            }
        }

        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
}
