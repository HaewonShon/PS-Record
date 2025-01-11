#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin>>s;

    string ans;

    if(s.find('x') != string::npos) // 항이 2개
    {
        int a = atoi(s.substr(0, s.find('x')).c_str());
        a /= 2;

        if(a != 1)
        {
            if(a == -1) ans += '-';
            else ans += to_string(a);
        }
        ans += "xx";

        s = s.substr(s.find('x') + 1);
    }

    if(s.length() > 0)
    {
        int b = atoi(s.c_str());

        if(b != 0)
        {
            if(b > 0 && ans.length() > 0) ans += '+';

            if(b != 1)
            {
                if(b == -1) ans += '-';
                else ans += to_string(b);
            }
            ans += "x";
        }
    }

    if(ans.length() == 0) cout<<"W";
    else cout<<ans<<"+W";
}