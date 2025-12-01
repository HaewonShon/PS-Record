#include <bits/stdc++.h>
using namespace std;

bool isPrime[3'000'001];
map<int, long long> memo;

long long CountCases(int p)
{
    if(memo[p] != 0)
    {
        return memo[p];
    }

    p -= 1;

    long long res = 1;
    for(int i = p/2; i >= 2; --i)
    {
        if(isPrime[i] && isPrime[p - i])
        {
            res = max(res, 1 + CountCases(i) + CountCases(p - i));
            break;
        }
    }

    memo[p + 1] = res;
    return res;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));

    int p;
    cin>>p;
    int sqrtP = (int)sqrt(p);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= sqrtP; ++i)
    {
        if(isPrime[i])
        {
            int j = i + i;
            while(j <= p)
            {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    cout<<CountCases(p);
}   