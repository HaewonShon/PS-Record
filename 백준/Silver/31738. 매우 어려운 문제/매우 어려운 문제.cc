#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    long long n, m;
    cin>>n>>m;

    if(n >= m) // m 포함-> 무조건 나눠떨어짐
    {
        cout<<0;
    }
    else
    {
        long long res = 1;

        while(n >= 2)
        {
            res *= n;
            res %= m;
            --n;
        }
        cout<<res;
    }
}