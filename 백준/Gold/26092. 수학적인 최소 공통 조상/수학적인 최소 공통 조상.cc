#include <bits/stdc++.h>
using namespace std;

bool isPrime[1'000'001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    long long x, y;
    cin>>x>>y;

    memset(isPrime, true, sizeof(isPrime));
    long long maxPrime = floor(sqrt(max(x, y)));

    vector<long long> primes;
    for(long long prime = 2; prime <= maxPrime; ++prime)
    {
        if(isPrime[prime])
        {
            primes.push_back(prime);
            long long nonPrime = prime + prime;
            while(nonPrime <= maxPrime)
            {
                isPrime[nonPrime] = false;
                nonPrime += prime;
            }
        }
    }

    queue<long long> xPrimes;
    queue<long long> yPrimes;

    long long xCopy = x, yCopy = y;
    int primeCount = primes.size();
    for(int primeIndex = 0; primeIndex < primeCount && (xCopy > 1 || yCopy > 1); ++primeIndex)
    {
        long long prime = primes[primeIndex];
        while(xCopy % prime == 0)
        {
            xCopy /= prime;
            xPrimes.push(prime);
        }
        while(yCopy % prime == 0)
        {
            yCopy /= prime;
            yPrimes.push(prime);
        }
    }

    if(xCopy > 1) xPrimes.push(xCopy);
    if(yCopy > 1) yPrimes.push(yCopy);

    while(x != y)
    {
        if(x > y)
        {
            x /= xPrimes.front();
            xPrimes.pop();
        }
        else
        {
            y /= yPrimes.front();
            yPrimes.pop();
        }
    }
    cout<<x;
}