
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test = 1; test <= t; ++test)
    {
        cout<<"Scenario #"<<test<<":\n";

        int m;
        cin>>m;

        vector<string> words(m);
        for(int i = 0; i < m; ++i)
        {
            cin>>words[i];
        }

        int n;
        cin>>n;

        while(n--)
        {
            string ans;
            int k;
            cin>>k;

            while(k--)
            {
                int index;
                cin>>index;
                ans += words[index];
            }
            cout<<ans<<"\n";
        }
        if(test < t) cout<<"\n";
    }


}