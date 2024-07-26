#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0) return a;

    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    long long A, B;
    cin>>A>>B;

    if(B % A != 0)
    {
        cout<<0;
        return 0;
    }

    int gcdAB = gcd(A, B);

    if(A != 1 && gcdAB == 1)
    {
        cout<<0;
        return 0;
    }

    A /= gcdAB;
    B /= gcdAB;

    int ans = 0;
    int i = 1;
    for(; i * i < B; ++i)
    {
        if(B % i == 0) ++ans;
    }
    ans *= 2;
    if(i * i == B) ++ans;
    
    cout<<ans;
}