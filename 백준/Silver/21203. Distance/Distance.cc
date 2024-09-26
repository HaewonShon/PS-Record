#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<long long> streets(n);
    vector<long long> avenues(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>streets[i]>>avenues[i];
    }

    sort(streets.begin(), streets.end());
    sort(avenues.begin(), avenues.end());

    long long ans = 0;
    
    long long streetSum = 0;
    long long avenueSum = 0;

    for(int i = 1; i < n; ++i)
    {
        streetSum = streetSum + (streets[i] - streets[i-1]) * i;
        avenueSum = avenueSum + (avenues[i] - avenues[i-1]) * i;
        ans += streetSum + avenueSum;
    }


    cout<<ans;
}