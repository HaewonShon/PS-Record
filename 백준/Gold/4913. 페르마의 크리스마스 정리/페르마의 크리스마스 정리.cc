#include <bits/stdc++.h>
using namespace std;

bool isPrime[1'000'001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));

    vector<int> primes;
    vector<int> possibleList;
    primes.push_back(2);
    possibleList.push_back(2);

    for(int i = 3; i <= 1000; i += 2)
    {
        if(isPrime[i])
        {
            int j = i + i;
            while(j <= 1'000'000)
            {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    for(int i = 3; i <= 1'000'000; i += 2)
    {
        if(isPrime[i])
        {
            if(i % 4 == 1) possibleList.push_back(i);
            primes.push_back(i);
        }
    }

    int l, u;
    while(cin>>l>>u)
    {
        if(l == -1 && u == -1) break;

        cout<<l<<" "<<u<<" "
            <<upper_bound(primes.begin(), primes.end(), u) - lower_bound(primes.begin(), primes.end(), l)<<" "
            <<upper_bound(possibleList.begin(), possibleList.end(), u) - lower_bound(possibleList.begin(), possibleList.end(), l)<<"\n";
    }
}