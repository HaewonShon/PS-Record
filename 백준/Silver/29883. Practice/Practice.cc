#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin>>v[i];
        v[i] += v[i-1];
    }

    set<int> s;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            s.insert(v[i]-v[j]);
        }
    }

    while(m--)
    {
        int y;
        cin>>y;

        if(s.find(y) == s.end())
        {
            cout<<"EI\n";
        }
        else
        {
            cout<<"JAH\n";
        }
    }
}