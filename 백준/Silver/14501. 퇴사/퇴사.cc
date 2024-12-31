#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> best(n+2, 0);

    for(int i = 1; i <= n; ++i)
    {
        int days, pay;
        cin>>days>>pay;

        for(int day = i + days; day <= n+1; ++day)
        {
            best[day] = max(best[day], best[i] + pay);
        }
    }

    cout<<*max_element(best.begin(), best.end());
}