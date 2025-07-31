#include <bits/stdc++.h>
using namespace std;

int minCount[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(minCount, 0x7f, sizeof(minCount));
    
    int n;
    cin>>n;

    minCount[0] = 0;

    for(int i = 0; i <= n; ++i)
    {
        int j = 1;
        while(i + j * j <= n)
        {
            minCount[i + j * j] = min(minCount[i + j * j], minCount[i] + 1);
            ++j;
        }
    }

    cout<<minCount[n];
}