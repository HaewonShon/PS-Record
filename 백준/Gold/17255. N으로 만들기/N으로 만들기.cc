#include <bits/stdc++.h>
using namespace std;

unordered_set<string> ans;

void DFS(const string& n, int nLen, const string& s, int sLen)
{
    if(sLen == nLen)
    {
        ans.insert(s);
        return;
    }

    for(int i = 0; i < nLen; ++i)
    {
        int sIndex = 0;
        for(sIndex = 0; sIndex < sLen; ++sIndex)
        {
            if(i + sIndex >= nLen) break;
            if(n[i + sIndex] != s[s.length() - sLen + sIndex]) break;
        }

        if(sIndex == sLen)
        {
            if(i > 0) DFS(n, nLen, s + n[i-1] + s.substr(s.length()-sLen), sLen + 1);
            if(i + sLen < nLen) DFS(n, nLen, s + s.substr(s.length()-sLen) + n[i + sLen], sLen + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);


    string n;
    cin>>n;
    int len = n.length();

    for(int i = 0; i < len; ++i)
    {
        DFS(n, len, string(1, n[i]), 1);
    }

    cout<<ans.size()<<"\n";
}