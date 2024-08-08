#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin>>v[i];

    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i)
    {
        for(int j = i-1; j >= 0; --j)
        {
            if(v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout<<*max_element(dp.begin(), dp.end());
}