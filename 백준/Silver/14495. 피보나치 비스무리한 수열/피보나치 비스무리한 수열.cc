#include <bits/stdc++.h>
using namespace std;

long long fibos[117];

long long Fibo(int n)
{
    if(fibos[n] != -1) return fibos[n];

    fibos[n] = Fibo(n-1) + Fibo(n-3);
    return fibos[n];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(fibos, -1, sizeof(fibos));

    int n;
    cin>>n;

    fibos[1] = 1;
    fibos[2] = 1;
    fibos[3] = 1;
    
    cout<<Fibo(n);
}