#include <bits/stdc++.h>
using namespace std;

bool isPrime[1001001];
bool isSquareNoNo[1000001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));
    memset(isSquareNoNo, true, sizeof(isSquareNoNo));

    long long min, max;
    cin>>min>>max;

    long long sqrtMax = (long long)sqrt(max);

    isPrime[0] = false;
    isPrime[1] = false;

    vector<long long> primeSquares;

    for(long long i = 2; i <= sqrtMax; ++i)
    {
        if(isPrime[i])
        {
            long long j = i + i;
            while(j <= sqrtMax)
            {
                isPrime[j] = false;
                j += i;
            }

            primeSquares.push_back(i * i);
        }
    }

    for(long long square : primeSquares)
    {
        long long val = min;
        if(val % square) val += square - (val % square);

        while(val <= max)
        {
            isSquareNoNo[val - min] = false;
            val += square;
        }
    }

    int ans = 0;
    for(int i = 0; i <= max - min; ++i)
    {
        if(isSquareNoNo[i]) ++ans;
    }

    cout<<ans;
}