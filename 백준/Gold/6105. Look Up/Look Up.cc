#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    stack<pair<int, int>> st;
    vector<int> ans(n+1);

    for(int i = 1; i <= n; ++i)
    {
        int h;
        cin>>h;

        while(!st.empty() && st.top().first < h)
        {
            ans[st.top().second] = i;
            st.pop();
        }

        st.push({h, i});
    }

    while(!st.empty())
    {
        ans[st.top().second] = 0;
        st.pop();
    }

    for(int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<"\n";
    }
}