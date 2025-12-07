#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 0;
    int totalAppleNum = 0;

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        char type;
        int a, b, c;
        cin>>type>>a>>b>>c;

        if(type == 'A')
        {
            int appleNum = (a / 12) * (b / 12) * (c / 12);
            totalAppleNum += appleNum;
            res += 1000 + appleNum * 500;
        }
        else if(type == 'B')
        {
            res += 6000;
        }
    }
    cout<<res<<'\n'<<4000 * totalAppleNum;
}   