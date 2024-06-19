#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int cMajor = 0;
    int aMinor = 0;
    char last;

    cin>>s;
    while(s.length() > 0)
    {
        if(s[0] == 'A' || s[0] == 'D' || s[0] == 'E')
        {
            ++aMinor;
        } 
        else if(s[0] == 'C' || s[0] == 'F' || s[0] == 'G')
        {
            ++cMajor;
        }

        if(s.find('|') == string::npos)
        {
            last = s.back();
            break;
        }
        else
        {
            s = s.substr(s.find('|') + 1);
        }
    }

    if(cMajor == aMinor)
    {
        if(last == 'A' || last == 'D' || last == 'E')
        {
            cout<<"A-minor";
        } 
        else if(last == 'C' || last == 'F' || last == 'G')
        {
            cout<<"C-major";
        }
    }
    else
    {
        if(cMajor > aMinor)
        {
            cout<<"C-major";
        }
        else
        {
            cout<<"A-minor";
        }
    }
}