#include <bits/stdc++.h>
using namespace std;

unsigned long long Calc(unsigned long long val)
{
    long long i = 63;
    unsigned long long res = 0;

    unsigned long long bitCount = 0;
    while(i >= 0)
    {
        if(val & ((unsigned long long int)(1) << i))
        {
            res += (bitCount * ((unsigned long long)(1) << i)) + (1 + i * ((unsigned long long)(1) << (i-1)));
            ++bitCount;
        }
        --i;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    unsigned long long A, B;
    cin>>A>>B;

    cout<<Calc(B) - Calc(A-1);

    for(int i = 0; i < 63; ++i)
    {
        //cout<<pow(2, i)<<" "<<((unsigned long long)(1) << i)<<"\n";
    }
}