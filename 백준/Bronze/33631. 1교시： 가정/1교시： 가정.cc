#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int s[4]; // 시작시 재료
    int n[4]; // 필요 재료

    for(int i = 0; i < 4; ++i) cin>>s[i];
    for(int i = 0; i < 4; ++i) cin>>n[i];

    int q;
    cin>>q;
    int cookieCount = 0;

    while(q--)
    {
        int cmd, i;
        cin>>cmd>>i;

        switch(cmd)
        {
            case 1:
            {
                int possibleCookieCount = INT_MAX;
                for(int j = 0; j < 4; ++j)
                {
                    possibleCookieCount = min(possibleCookieCount, s[j] / n[j]);
                }
                if(possibleCookieCount < i)
                {
                    cout<<"Hello, siumii\n";
                }
                else
                {
                    for(int j = 0; j < 4; ++j)
                    {
                        s[j] -= n[j] * i;
                    }
                    cookieCount += i;
                    cout<<cookieCount<<"\n";
                }
            }
            break;
            case 2:
            case 3:
            case 4:
            case 5:
                s[cmd-2] += i;
                cout<<s[cmd-2]<<"\n";
            break;
        }
    }
}