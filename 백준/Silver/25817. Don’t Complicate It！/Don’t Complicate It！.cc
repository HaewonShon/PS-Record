#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s;
    getline(cin, s);

    stack<int> st;
    int ans = 0;

    for(char c : s)
    {
        if(c == '(')
        {
            st.push(1);
        }
        else if(c == ')')
        {
            int depth = st.top();
            ans += depth;
            st.pop();
            if(!st.empty())
            {
                st.top() = max(st.top(), depth + 1);
            }
        }
    }
    cout<<ans;
}
