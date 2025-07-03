#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    int res = v[0];

    for(int i = 1; i < n; ++i)
    {
        if(v[i] == v[i-1]) continue;
        
        if(v[i] == 0)
        {
            continue;
        }
        else
        {
            ++res;
        }
    }

    for(int i = 0; i < m; ++i)
    {
        int cmd;
        cin>>cmd;

        if(cmd == 0)
        {
            cout<<res<<"\n";
        }
        else
        {
            int index;
            cin>>index;
            --index;
            if(v[index] == 1) continue;
            
            v[index] = 1;
            if(index == 0)
            {
                if(n == 1 || v[1] == 0) ++res;
            }
            else if(index == n-1)
            {
                if(n == 1 || v[n-2] == 0) ++res;
            }
            else
            {
                if(v[index-1] == 0 && v[index+1] == 0) ++res;
                else if(v[index-1] == 1 && v[index+1] == 1) --res;
            }
        }
    }
}