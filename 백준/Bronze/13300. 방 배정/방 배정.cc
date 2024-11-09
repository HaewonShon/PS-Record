#include <bits/stdc++.h>
using namespace std;

int status[7][2];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    memset(status, 0, sizeof(status));

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int s, y;
        cin>>s>>y;

        if(++status[y][s] % k == 1) ++ans;
    }
    cout<<ans;
}