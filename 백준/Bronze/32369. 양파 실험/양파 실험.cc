#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin>>n>>a>>b;

    int good = 1, bad = 1;

    for(int i = 0; i < n; ++i)
    {
        good += a;
        bad += b;

        if(bad > good) swap(good, bad);
        else if(good == bad) bad -= 1;
    }

    cout<<good<<" "<<bad;
}