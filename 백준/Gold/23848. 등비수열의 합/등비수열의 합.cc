#include <bits/stdc++.h>
using namespace std;

bool isPrime[1'000'000];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));

    long long n;
    cin>>n;

    long long primeMaxRange = (int)sqrt(n);

    // vector<long long> prime;

    // for(long long i = 2; i <= primeMaxRange; ++i)
    // {
    //     if(isPrime[i])
    //     {
    //         prime.push_back(i);

    //         long long j = i + i;
    //         while(j <= primeMaxRange)
    //         {
    //             isPrime[j] = false;
    //             j += i;
    //         }
    //     }        
    // }

    for(long long p = 2; p <= primeMaxRange; ++p)
    {
        long long a = p * p + p + 1;
        long long power = p * p * p;
        int k = 2;

        while(a <= n)
        {
            if(n % a == 0)
            {
                cout<<k + 1<<"\n";

                long long val = n / a;
                long long multiplier = 1;
                for(int i = 0; i <= k; ++i)
                {
                    cout<<multiplier * val<<" ";
                    multiplier *= p;
                }
                return 0;
            }
            else
            {
                a += power;
                power *= p;
                ++k;
            }
        }
    }

    cout<<-1;
}