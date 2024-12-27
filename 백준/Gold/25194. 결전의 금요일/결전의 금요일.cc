#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    bool hasEndCase[7] = { false };
    hasEndCase[0] = true;

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        int workDays;
        cin>>workDays;

        workDays %= 7;

        bool nextEndCase[7] = { false };
        for(int j = 0; j < 7; ++j)
        {
            if(hasEndCase[j]) nextEndCase[(j + workDays) % 7] = true;
        }
        for(int j = 0; j < 7; ++j) if(nextEndCase[j]) hasEndCase[j] = true;

        if(hasEndCase[4]) break;
    }

    if(hasEndCase[4]) cout<<"YES";
    else cout<<"NO";


}