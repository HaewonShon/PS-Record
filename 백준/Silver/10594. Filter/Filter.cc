#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, f;
    cin>>m>>f;

    vector<int> a(f);
    for(int i = 0; i < f; ++i)
    {
        cin>>a[i];
    }

    int s;
    cin>>s;
    vector<string> data(s);
    for(int i = 0; i < s; ++i)
    {
        cin>>data[i];
    }

    int q;
    cin>>q;
    vector<int> users(q);
    for(int i = 0; i < q; ++i)
    {
        cin>>users[i];
    }

    vector<int> ans;
    for(int i = 0; i < s; ++i)
    {
        for(int user : users)
        {
            int hash = 0;
            for(; hash < f; ++hash)
            {
                long long res = (long long)a[hash] * (long long)user;
                res %= m;

                int index = res / 4;
                int offset = res % 4;

                char c = data[i][index];
                if(isalpha(c))
                {
                    c = c - 'a' + 10;
                }
                else
                {
                    c = c - '0';
                }

                bool hasBit = c & (1 << offset);
                if(!hasBit)
                {
                    break;
                }
            }

            if(hash == f)
            {
                ans.push_back(i);
                break;
            }
        }
    }

    cout<<ans.size()<<" ";
    for(int i : ans)
    {
        cout<<i<<" ";
    }
}   