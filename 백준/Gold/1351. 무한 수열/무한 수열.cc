#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> m;

long long Calc(long long n, long long p, long long q)
{
    if(n == 0) return 1;
    if(m.find(n) != m.end()) return m[n];
    return m[n] = Calc(n / p, p, q) + Calc(n / q, p, q);
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, p, q;
    cin>>n>>p>>q;

    cout<<Calc(n, p, q);
}