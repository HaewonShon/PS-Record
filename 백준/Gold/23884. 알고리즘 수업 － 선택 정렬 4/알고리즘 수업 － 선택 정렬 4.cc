#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    map<int, int> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
        m.insert({v[i], i});
    }

    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    int exchanges = 0;
    int last = n-1;
    while(exchanges < k && last > 0)
    {
        if(v[last] == sorted[last])
        {
            --last;
            continue;
        }
        
        int targetIndex = m[sorted[last]];
        swap(v[last], v[targetIndex]);
        swap(m[v[last]], m[v[targetIndex]]);

        ++exchanges;
        --last;
    }

    if(exchanges < k)
    {
        cout<<-1;
    }
    else
    {
        for(int val : v)
        {
            cout<<val<<" ";
        }
    }

}