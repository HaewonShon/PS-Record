#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    string s;
    cin>>s;

    for(int i = 0; i < m; ++i)
    {
        string t;
        cin>>t;
        int tIndex = 0;
        int tLen = t.length();
        int sIndex = 0;

        while(tIndex < tLen && sIndex < n)
        {
            if(s[sIndex] == t[tIndex]) ++sIndex;
            ++tIndex;
        }

        if(sIndex == n)
        {
            cout<<"true\n";
        }
        else
        {
            cout<<"false\n";
        }

    }
}