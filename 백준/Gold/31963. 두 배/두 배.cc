#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    long long prev;
    cin>>prev;

    long long int lsh = 0;
    long long ans = 0;
    for(int i = 1; i < n; ++i)
    {
        long long val;
        cin>>val;

        if(prev > val)
        {
            int requiredLsh = 0;
            while(prev > (val << requiredLsh))
            {
                ++requiredLsh;
            }

            lsh += requiredLsh;
        }
        else
        {
            int rsh = 0;
            while(prev < (val >> rsh)) 
            {
                ++rsh;
            }
            lsh = max(lsh - rsh, (long long)0);
        }

        ans += lsh;
        prev = val;
    }
    cout<<ans;
}
