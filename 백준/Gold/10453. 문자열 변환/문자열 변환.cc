#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        string a, b;
        cin>>a>>b;

        if(a.length() != b.length())
        {
            cout<<"-1\n";
            continue;
        }

        int n = a.length();
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(a[i] == b[i]) continue;

            if(a[i] == 'a')
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if(a[j] == 'b')
                    {
                        swap(a[i], a[j]);
                        ans += j - i;
                        break;
                    }
                }
            }
            else // == 'b'
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if(a[j] == 'a')
                    {
                        swap(a[i], a[j]);
                        ans += j - i;
                        break;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
