#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    int singlePriceMin = INT_MAX, setPriceMin = INT_MAX;

    for(int i = 0; i < m; ++i)
    {
        int singlePrice, setPrice;
        cin>>setPrice>>singlePrice;

        singlePriceMin = min(singlePrice, singlePriceMin);
        setPriceMin = min(setPrice, setPriceMin);
    }

    
    int ans = 0;
    if(singlePriceMin * 6 < setPriceMin)
    {
        ans = singlePriceMin * n;
    }
    else if(setPriceMin < singlePriceMin)
    {
        ans = setPriceMin * (n/6 + ((n%6) ? 1 : 0));
    }
    else
    {
        int set = n / 6;
        int remainder = n % 6;

        ans += setPriceMin * set;
        if(remainder > 0)
        {
            if(remainder * singlePriceMin < setPriceMin)
            {
                ans += remainder * singlePriceMin;
            }
            else
            {
                ans += setPriceMin;
            }
        }
    }

    cout<<ans;
}
