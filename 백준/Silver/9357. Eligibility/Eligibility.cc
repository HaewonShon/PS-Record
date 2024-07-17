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
        int n;
        cin>>n;
        cin.get();

        map<string, set<int>> m;
        for(int i = 0; i < n; ++i)
        {
            string s;
            getline(cin, s);
            int year;
            year = atoi(s.substr(s.find_last_of(' ') + 1).c_str());
            s = s.substr(0, s.find_last_of(' '));
            m[s].insert(year);
        }

        cout<<"Case #"<<test<<":\n";
        for(auto p : m)
        {
            if(p.second.size() < 5) cout<<p.first<<"\n";
        }
    }
}