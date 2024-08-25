#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s;
    cin>>s;

    string ans(s.length(), 'z');

    int n = s.length();
    for(int i = 1; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            string cpy(s);
            reverse(cpy.begin(), cpy.begin() + i);
            reverse(cpy.begin() + i, cpy.begin() + j);
            reverse(cpy.begin() + j, cpy.end());
            ans = min(cpy, ans);
        }
    }

    cout<<ans;
}
