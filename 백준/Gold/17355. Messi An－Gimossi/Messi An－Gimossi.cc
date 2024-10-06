#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

long long Power(long long val, long long pow)
{
    long long res = 1;

    while(pow > 0)
    {
        if(pow & 1)
        {
            res *= val;
            res %= MOD;
        }
        pow >>= 1;
        val *= val;
        val %= MOD;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    bool isPrime[5001];
    memset(isPrime, true, sizeof(isPrime));

    vector<int> primes;
    
    for(int i = 2; i <= 5000; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i + i; j <= 5000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    map<int, int> elements; // {elements, count} - 양수->분자, 음수->분모

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin>>a>>b;
        a = b-a;

        for(int prime : primes)
        {
            while(a % prime == 0)
            {
                ++elements[prime];
                a /= prime;
            }

            while(b % prime == 0)
            {
                --elements[prime];
                b /= prime;
            }
        }
        
        if(a > 1) ++elements[a];
        if(b > 1) --elements[b];
    }

    long long A = 1, B = 1;

    for(auto p : elements)
    {
        if(p.second > 0)
        {
            A *= Power(p.first, p.second);
            A %= MOD;
        }
        else if(p.second < 0)
        {
            B *= Power(p.first, -p.second);
            B %= MOD;
        }
    }
    cout<<A<<" "<<B;
}
