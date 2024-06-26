#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    // int range
    if(s.length() < 10)
    {
        int val = atoi(s.c_str());
        cout<<val + max(0, val - 2);
        return 0;
    }

    string ans; // == val * 2 - 2;

    // val * 2
    bool roundUp = false;
    for(auto it = s.rbegin(); it != s.rend(); ++it)
    {
        int val = (*it) - '0';
        val *= 2;
        if(roundUp)
        {
            roundUp = false;
            val += 1;
        }

        if(val >= 10)
        {
            roundUp = true;
            val -= 10;
        }

        char c = '0' + val;
        ans = c + ans;
    }

    if(roundUp)
    {
        ans = '1' + ans;
    }

    // -2
    ans.back() -= 2;
    auto it = ans.rbegin();
    while(*it < '0')
    {
        *it += 10;
        ++it;
        *it -= 1;
    }

    // remove 0 in front
    if(ans.front() == '0')
    {
        ans = ans.substr(1);
    }

    cout<<ans;
}   