#include <bits/stdc++.h>
using namespace std;

int maxLen[1001];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(maxLen, 0, sizeof(maxLen));

    int n;
    cin>>n;

    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin>>v[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        int prev = 0;
        for(int j = 1; j < i; ++j)
        {
            if(v[j] < v[i] && maxLen[j] > maxLen[prev]) prev = j;
        }

        maxLen[i] = maxLen[prev] + 1;
    }

    int last = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(maxLen[last] < maxLen[i]) last = i;
    }

    stack<int> ans;
    while(last != 0)
    {
        ans.push(last);
        for(int i = last - 1; i >= 0; --i)
        {
            if(v[i] < v[last] && maxLen[i] == maxLen[last] - 1)
            {
                last = i;
                break;
            }
        }
    }

    cout<<ans.size()<<"\n";
    while(!ans.empty())
    {
        cout<<v[ans.top()]<<" ";
        ans.pop();
    }
}