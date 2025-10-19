#include <bits/stdc++.h>
using namespace std;

bool isPrime[300'001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;

    vector<int> primes;
    // 42857 - 30만 이하 월-토 생성가능한 최대 N
    for(int i = 0; i <= 42857; ++i) 
    {
        int val = i * 7 + 1;
        if(val <= 300'000 && isPrime[val])
        {
            primes.push_back(val);
            int mult = val * 2;
            while(mult <= 300'000)
            {
                isPrime[mult] = false;
                mult += val;
            }
        }

        val = i * 7 + 6;
        if(val <= 300'000 && isPrime[val])
        {
            primes.push_back(val);
            int mult = val * 2;
            while(mult <= 300'000)
            {
                isPrime[mult] = false;
                mult += val;
            }
        }
    }

    sort(primes.rbegin(), primes.rend());

    int v;
    while (cin>>v)
    {
        if(v == 1) break;

        cout<<v<<": ";

        std::set<int> res;
        
        for(int prime : primes)
        {
            if(v % prime == 0)
            {
                std::set<int> divider;

                divider.insert(prime);
                int vCopy = v;
                while(vCopy % prime == 0)
                {
                    vCopy /= prime;
                }

                for(int prime2 : primes)
                {
                    if(vCopy % prime2 == 0)
                    {
                        divider.insert(prime2);
                        while(vCopy % prime2 == 0)
                        {
                            vCopy /= prime2;
                        }
                    }

                    if(vCopy == 1)
                    {
                        break;
                    }
                }

                if(vCopy == 1)
                {
                    for(int d : divider)
                    {
                        res.insert(d);
                    }
                }
            }
        }

        for(int prime : res)
        {
            cout<<prime<<" ";
        }
        cout<<"\n";
    }
}   