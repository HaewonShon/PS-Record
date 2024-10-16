#include <bits/stdc++.h>
using namespace std;

bool isPrime[100001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int a, b;
    cin>>a>>b;

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= 100000; ++i)
    {
        if(isPrime[i])
        {
            for(int j = i + i; j <= 100000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int ans = 0;
    for(int val = a; val <= b; ++val)
    {
        int copyVal = val;
        int primeCount = 0;
        for(int prime = 2; prime <= b && copyVal > 1; ++prime)
        {
            if(isPrime[prime])
            {
                while(copyVal % prime == 0)
                {
                    copyVal /= prime;
                    ++primeCount;
                }
            }
        }

        if(isPrime[primeCount]) ++ans;
    }
    cout<<ans;
}