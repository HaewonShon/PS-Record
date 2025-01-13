#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        set<int> s;

        for(int i = 0; i < n; ++i)
        {
            int v;
            cin>>v;
            s.insert(v);
        }

        int m;
        cin>>m;

        for(int i = 0; i < m; ++i)
        {
            int v;
            cin>>v;

            if(s.find(v) != s.end()) cout<<"1\n";
            else cout<<"0\n";
        }
    }
}