#include <bits/stdc++.h>
using namespace std;

bool IsPossibleCase(const string& s, int index, int halfLen)
{
    if(halfLen == 0) return true;

    for(int i = 1; i <= halfLen; ++i)
    {
        if(s[index + i] == s[index - i]) return false;
    }
    return IsPossibleCase(s, index - (halfLen/2 + 1), halfLen/2) && IsPossibleCase(s, index + (halfLen/2 + 1), halfLen/2);
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

        if(IsPossibleCase(s, s.length()/2, s.length()/2)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}