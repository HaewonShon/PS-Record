#include <bits/stdc++.h>
using namespace std;

const int MAX_YEAR = 10000;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int e, s, m;
    cin>>e>>s>>m;

    if(e == 15) e = 0;
    if(s == 28) s = 0;
    if(m == 19) m = 0;

    for(int i = 1; i <= MAX_YEAR; ++i)
    {
        if(i % 15 == e
            && i % 28 == s
            && i % 19 == m)
        {
            cout<<i;
            return 0;
        }
    }
}
