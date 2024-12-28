#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    map<string, int> m;
    for(int i = 0; i < n; ++i)
    {
        string book;
        cin>>book;
        ++m[book];
    }

    string ans;
    int count = 0;
    for(auto& p : m)
    {
        if(count < p.second)
        {
            count = p.second;
            ans = p.first;
        }
    }
    cout<<ans;
}