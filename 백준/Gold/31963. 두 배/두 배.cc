#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int prev;
    cin>>prev;
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        int val;
        cin>>val;

        while(val < prev)
        {
            val <<= 1;
            ++ans;
        }
        prev = val;
    }
    cout<<ans;
}
