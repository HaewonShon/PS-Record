#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    unsigned long long a, b;
    cin>>a>>b;

    if(b == 1)
    {
        if(a == 0) cout<<"-";
        else cout<<"*";
        return 0;
    }

    if(b % 2 == 0)
    {
        cout<<-1;
        return 0;
    }

    for(unsigned long long i = 1; i <= 60; ++i)
    {
        if((((unsigned long long)1 << i) - 1) % b == 0)
        {
            unsigned long long multiplier = (((unsigned long long)1 << i) - 1) / b;
            a *= multiplier;
            b *= multiplier;
            
            // greedy
            string ans;
            for(unsigned long long j = i-1; j >= 0 && j < i; --j)
            {
                if(a >= ((unsigned long long)1 << j))
                {
                    a -= (unsigned long long)1 << j;
                    ans += '*';
                }
                else
                {
                    ans += '-';
                }
            }

            cout<<ans;
            return 0;
        }
    }
    cout<<-1;
}
