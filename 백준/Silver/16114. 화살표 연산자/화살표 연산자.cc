#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int x, n;
    cin>>x>>n;

    int subPerLoop = n / 2;

    if(subPerLoop == 0)
    {
        if(n == 1) x = -x;
        if(x > 0) cout<<"INFINITE";
        else cout<<0;

        return 0;
    }

    if(n % 2 == 1)
    {
        cout<<"ERROR";
        return 0;
    }

    int count = 0;
    x -= subPerLoop;
    while(x > 0)
    {
        ++count;
        x -= subPerLoop;
    }
    cout<<count;
}