#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    while(cin>>x)
    {
        if(x == 0) break;

        long long sqrtX = (long long)sqrt(abs(x));

        long long i = 2;
        for(; i <= sqrtX; ++i)
        {
            long long ans = 0;

            long long _x = abs(x);
            while(_x >= i)
            {
                if(_x % i != 0)
                {
                    break;
                }

                _x /= i;
                ++ans;
            }

            if(_x == 1)
            {
                if(!(x < 0 && ans % 2 == 0))
                {
                    cout<<ans<<"\n";
                    break;
                }
            }
        }

        if(i > sqrtX)
        {
            cout<<"1\n";
        }
    }
}   
