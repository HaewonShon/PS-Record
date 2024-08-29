#include <bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long A, unsigned long long B)
{
    if(B == 0) return A;
    return gcd(B, A % B);
}

unsigned long long Power(unsigned long long val, unsigned long long times)
{
    unsigned long long res = 1;
    while(times-- > 0)
    {
        res *= val;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, K;
    cin>>n>>m>>K;

    unsigned long long total = m * 3;
    vector<int> frequency(n+1, 0);
    for(int i = 0; i < m-1; ++i)
    {
        int a, b, c;
        cin>>a>>b>>c;

        ++frequency[a];
        ++frequency[b];
        ++frequency[c];
    }
    unsigned long long maxProbability = 0;
    vector<int> ans(3, -1);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            for(int k = j+1; k <= n; ++k)
            {
                unsigned long long pickedFrequency = frequency[i] + frequency[j] + frequency[k] + 3;
                unsigned long long remainedFrequency = total - pickedFrequency;

                unsigned long long currentProbability = Power(remainedFrequency, K) * pickedFrequency;
                if(maxProbability < currentProbability)
                {
                    maxProbability = currentProbability;
                    ans[0] = i;
                    ans[1] = j;
                    ans[2] = k;
                }                
            }
        }
    }

    unsigned long long divider = Power(total, K+1);
    unsigned long long gcdRes = gcd(divider, maxProbability);
    maxProbability /= gcdRes;
    divider /= gcdRes;

    cout<<maxProbability<<" "<<divider<<"\n";
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];

}
