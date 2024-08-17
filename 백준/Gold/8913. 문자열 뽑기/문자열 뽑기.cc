#include <bits/stdc++.h>
using namespace std;

bool Remove(string s)
{
    if(s.length() == 0) return true;

    vector<pair<int, int>> v; // {count, index}
    v.push_back({1, 0});

    int n = s.length();
    for(int i = 1; i < n; ++i)
    {
        if(s[i] == s[i-1]) ++v.back().first;
        else v.push_back({1, i});
    }

    for(auto p : v)
    {
        if(p.first > 1)
        {
            string newString = s.substr(0, p.second) + s.substr(p.second + p.first);
            if(Remove(newString)) return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        if(Remove(s)) cout<<"1\n";
        else cout<<"0\n";
    }
}
