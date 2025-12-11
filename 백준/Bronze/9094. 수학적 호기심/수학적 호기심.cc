    #include <bits/stdc++.h>
    using namespace std;

    int main()
    { 
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin>>t;

        while(t--)
        {
            int n, m;
            cin>>n>>m;

            int res = 0;
            for(int a = 1; a < n; ++a)
            {
                for(int b = a + 1; b < n; ++b)
                {
                    if((a * a + b * b + m) % (a * b) == 0)
                    {
                        ++res;
                    }
                }
            }
            cout<<res<<"\n";
        }
    }   