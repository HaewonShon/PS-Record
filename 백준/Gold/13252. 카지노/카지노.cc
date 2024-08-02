#include <bits/stdc++.h>
using namespace std;

map<long long, double> dp[51]; // {round, {left, probability}}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    long long n, m, k;
    cin>>n>>m>>k;

    dp[0].insert({n, 1.0});

    for(int i = 0; i < k; ++i)
    {
        for(auto p : dp[i])
        {
            long long chips = p.first;
            double probability = p.second;

            if(abs(probability) < numeric_limits<double>().epsilon()) continue; // 확률이 0이면 무시

            long long minChip = chips / m;
            long long maxChip = minChip + (chips % m ? 1 : 0);
            double maxProbability = (double)(chips % m) / (double)m;
            double minProbability = 1.0 - maxProbability;            


            dp[i+1][chips - minChip] += probability * minProbability;
            dp[i+1][chips - maxChip] += probability * maxProbability;
        }
    }

    double ans = 0.0;
    for(auto p : dp[k])
    {
        if(p.first == 0 || abs(p.second) < numeric_limits<double>().epsilon()) continue;
        ans += p.second;
    }
    cout<<ans;
}