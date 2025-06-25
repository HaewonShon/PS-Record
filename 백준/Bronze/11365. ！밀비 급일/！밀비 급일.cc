#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while(getline(cin, s))
    {
        if(s == "END") break;

        reverse(s.begin(), s.end());
        cout<<s<<"\n";
    }   
}
