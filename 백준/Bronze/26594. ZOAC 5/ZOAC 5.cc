#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 1;
    char c, newC;
    cin>>c;

    while(cin>>newC)
    {
        if(c != newC) break;
        else ++res;
    }

    cout<<res;
}