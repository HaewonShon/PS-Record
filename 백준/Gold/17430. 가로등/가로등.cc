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
        int n;
        cin>>n;

        map<int, set<int>> m;

        for(int i = 0; i < n; ++i)
        {
            int x, y;
            cin>>x>>y;

            m[x].insert(y);
        }

        bool isBalanced = true;
        auto begin = m.begin();
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(begin->second != it->second)
            {
                isBalanced = false;
                break;
            }
        }

        if(isBalanced) cout<<"BALANCED\n";
        else cout<<"NOT BALANCED\n";
    }    
}
