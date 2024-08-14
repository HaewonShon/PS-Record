#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<vector<int>> groups(k);
    for(int i = 0; i < k; ++i)
    {
        int size;
        cin>>size;
        for(int j = 0; j < size; ++j)
        {
            int val;
            cin>>val;
            groups[i].push_back(val);
        }
    }

    for(auto& group : groups)
    {
        sort(group.begin(), group.end());
    }

    vector<int> indices(k, 0);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            if(indices[j] < groups[j].size() && groups[j][indices[j]] + indices[j] == i)
            {
                groups[j][indices[j]] = i;
                ++indices[j];
                break;
            }
        }
    }

    for(auto& group : groups)
    {
        for(int i : group)
        {
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
}