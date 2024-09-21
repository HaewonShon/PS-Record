#include <bits/stdc++.h>
using namespace std;

const int MAX = 30000;
bool isPrime[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = false;
    isPrime[1] = false;

    vector<int> primes;
    for(int i = 2; i <= MAX; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);

            int multiples = i + i;
            while(multiples <= MAX)
            {
                isPrime[multiples] = false;
                multiples += i;
            }
        }
    }    


    int t;
    cin>>t;


    while(t != 0)
    {
        int ans = 0;

        for(int i = upper_bound(primes.begin(), primes.end(), (t-1)/2) - primes.begin() - 1; i >= 0; --i)
        {
            for(int j = i; j >= 0; --j)
            {
                int val = t - primes[i] - primes[j];
                if(val <= primes[j] && isPrime[val] == true)
                {
                    ++ans;
                }
            }    
        }

        cout<<ans<<"\n";
        cin>>t;
    }
}