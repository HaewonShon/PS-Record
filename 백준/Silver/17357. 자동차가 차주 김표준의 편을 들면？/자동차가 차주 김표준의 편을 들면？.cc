#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n+1, 0);
    vector<int> sum(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin>>v[i];
        sum[i] = sum[i-1] + v[i];
    }

    for(int k = 1; k <= n; ++k)
    {
        long double bestV = -1;
        int ans = -1;

        for(int i = 0; i <= n-k; ++i)
        {
            long double avg = (sum[i+k] - sum[i]);// / k;

            long double V = 0;
            for(int j = i+1; j <= i+k; ++j)
            {
                long double val = (long double)(v[j]) * k - avg;
                V += val * val;
            }

            if(V > bestV)
            {
                ans = i;
                bestV = V;
            }
        }

        cout<<ans + 1<<"\n";
    }
}