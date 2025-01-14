#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;

    getline(cin, s);

    if(s.find("d2") == string::npos && s.find("D2") == string::npos)
    {
        cout<<"unrated";
    }
    else
    {
        cout<<"D2";
    }
}