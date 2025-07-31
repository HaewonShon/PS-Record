#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, m, k, d;
        cin>>n>>m>>k>>d;

        int matchesInEachLeague = n * m * (m-1) / 2;
        int matchesOutOfLeague = (n * m) * (n * m - 1) / 2 - matchesInEachLeague;

        int multiplier = matchesInEachLeague * k + matchesOutOfLeague;
        int b = d / multiplier;
        if(b == 0) cout<<"-1\n";
        else cout<<b*multiplier<<"\n";
    }
}