#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int v;
        cin>>v;

        if(v == 0)
        {
            cout<<"0\n";
            continue;
        }

        long long ans = 0;
        int target = ceil(log2(abs(v))) * 2 + ((v < 0) ? 1 : 0);

        int curr = 0;
        for(int i = 0; i < target; ++i)
        {
            int next = 1 << (i / 2);
            if(i % 2 == 1) next *= -1;

            ans += abs(curr - next);
            curr = next;
        }

        ans += abs(curr - v);
        cout<<ans<<"\n";
    }
}