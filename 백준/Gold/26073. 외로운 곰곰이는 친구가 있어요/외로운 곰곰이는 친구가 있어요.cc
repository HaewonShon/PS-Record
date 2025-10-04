#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int x, y;
        cin>>x>>y;

        x = abs(x);
        y = abs(y);

        int n;
        cin>>n;

        int gcd;
        cin>>gcd;
        for(int i = 1; i < n; ++i)
        {
            int val;
            cin>>val;

            gcd = GCD(gcd, val);
        }

        if(x % gcd == 0 && y % gcd == 0)
        {
            cout<<"Ta-da\n";
        }
        else
        {
            cout<<"Gave up\n";
        }
    }
}   