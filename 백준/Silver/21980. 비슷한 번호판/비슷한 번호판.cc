#include <bits/stdc++.h>
using namespace std;

bool AreSimilar(string& p1, string& p2, int k)
{
    for(int i = 0; i < k; ++i)
    {
        if(p1[i] != p2[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        vector<unordered_map<string, int>> plates(k+1); // {ordered string, count}
        for(int i = 0; i < n; ++i)
        {
            string s;
            cin>>s;
            int uppers = 0;
            for(int i = 0; i < k; ++i)
            {
                if(isupper(s[i]))
                {
                    s[i] += 'a' - 'A';
                    ++uppers;
                }
            }
            sort(s.begin(), s.end());
            ++plates[uppers][s];
        }

        int ans = 0;
        for(auto m : plates)
        {
            for(auto p : m)
            {
                ans += (p.second * (p.second - 1)) / 2;
            }
        }
        cout<<ans<<"\n";
    }
}