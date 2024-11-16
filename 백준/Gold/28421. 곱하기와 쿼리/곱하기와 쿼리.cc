#include <bits/stdc++.h>
using namespace std;

int counts[10001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(counts, 0, sizeof(counts));

    int n, q;
    cin>>n>>q;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
        ++counts[v[i]];
    }

    int cmd, param;
    while(q--)
    {
        cin>>cmd>>param;

        if(cmd == 1)
        {
            if(param == 0)
            {
                if(n > 1 && counts[0] > 0)
                {
                    cout<<"1\n";
                } 
                else
                {
                    cout<<"0\n";
                } 
                continue;
            }

            int i = 1;
            for(; i * i <= param; ++i)
            {
                if(param % i == 0)
                {
                    int j = param / i;
                    if(j <= 10000)
                    {
                        if(i == j)
                        {
                            if(counts[i] >= 2) break;
                        }
                        else
                        {
                            if(counts[i] > 0 && counts[j] > 0) break;
                        }
                    }
                }
            }
            
            if(i * i > param)
            {
                cout<<"0\n";
            }
            else
            {
                cout<<"1\n";
            }
        }
        else
        {
            if(v[param-1] == -1) continue;

            --counts[v[param-1]];
            ++counts[0];
            v[param-1] = -1;
        }
    }
}