#include <bits/stdc++.h>
using namespace std;

bool Step(const string& s, string t, bool isReversed)
{
    if(s.length() == t.length())
    {
        if(isReversed) reverse(t.begin(), t.end());
        if(s == t) return true;
        return false;
    }

    bool res = false;
    if(isReversed)
    {
        if(t.front() == 'A') res |= Step(s, t.substr(1), isReversed);
        if(t.back() == 'B') res |= Step(s, t.substr(0, t.length()-1), !isReversed);        
    }
    else
    {
        if(t.front() == 'B') res |= Step(s, t.substr(1), !isReversed);
        if(t.back() == 'A') res |= Step(s, t.substr(0, t.length()-1), isReversed);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s, t;
    cin>>s>>t;

    cout<<Step(s, t, false);
}