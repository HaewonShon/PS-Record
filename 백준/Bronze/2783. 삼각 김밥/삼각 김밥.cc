#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    float x, y;
    int n;
    cin>>x>>y>>n;

    float bestPrice = x * (1000 / y);
    while(n--)
    {
        float _x, _y;
        cin>>_x>>_y;
        bestPrice = min(bestPrice, _x * (1000 / _y));
    }

    cout.precision(2);
    cout<<fixed;
    cout<<bestPrice;
}