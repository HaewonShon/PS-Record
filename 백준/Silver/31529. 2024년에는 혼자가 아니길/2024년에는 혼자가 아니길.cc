#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin>>x>>y;

    if(x > y || 2*x - y < 0)
    {
        cout<<-1;
    }
    else
    {
        cout<<506 * (2*x - y);
    }
}