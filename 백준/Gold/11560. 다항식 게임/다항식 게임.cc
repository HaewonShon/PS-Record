#include <bits/stdc++.h>
using namespace std;

const int MAX_POWER = 210;
unsigned long long multiplier[21][211];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(multiplier, 0, sizeof(multiplier));

    multiplier[1][0] = 1;
    multiplier[1][1] = 1;
    
    for(int i = 2; i <= 20; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            for(int k = 0; j + k <= MAX_POWER; ++k)
            {
                multiplier[i][j + k] += multiplier[i-1][k];
            }
        }
    }


    int t;
    cin>>t;

    while(t--)
    {
        int k, n;
        cin>>k>>n;

        cout<<multiplier[k][n]<<"\n";
    }
}