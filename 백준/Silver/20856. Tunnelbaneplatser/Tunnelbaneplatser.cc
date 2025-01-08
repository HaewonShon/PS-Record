#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int g1, g2, g3, g4;
    cin>>g1>>g2>>g3>>g4;

    int ans = g4;

    ans += g3;
    g1 -= g3;

    ans += g2 / 2;
    g2 %= 2;

    if(g2 == 1)
    {
        ans += 1;
        g1 -= 2;
    }

    if(g1 > 0)
    {
        ans += g1 / 4;
        g1 %= 4;
        if(g1 > 0) ans += 1;
    }

    cout<<ans;
}