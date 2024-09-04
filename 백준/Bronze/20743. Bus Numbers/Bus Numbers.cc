#include <bits/stdc++.h>
using namespace std;

int res[400001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int m;
    cin>>m;

    memset(res, 0, sizeof(res));

    vector<int> candidates;
    for(int i = 1; i * i * i <= m; ++i)
    {
        candidates.push_back(i * i * i);
    }

    int n = candidates.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(candidates[i] + candidates[j] <= m)
            {
                ++res[candidates[i] + candidates[j]];
            }
        }
    }

    while(m > 0)
    {
        if(res[m] >= 2)
        {
            cout<<m;
            return 0;
        }
        --m;
    }
    cout<<"none";
}
