#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<int>>& friends, vector<bool>& picked, int index, int n, int curr, int& ans)
{
    ans = max(ans, curr);

    if(curr == n)
    {
        return;
    }

    for(int i = index; i <= n; ++i)
    {
        if(picked[i] == false)
        {
            picked[i] = true;
            for(int fr : friends[i])
            {
                if(picked[fr] == false)
                {
                    picked[fr] = true;
                    DFS(friends, picked, i + 1, n, curr + 2, ans);
                    picked[fr] = false;
                }
            }

            picked[i] = false;
        }
    }
} 

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> friends(n+1);

    while(m--)
    {
        int a, b;
        cin>>a>>b;
        friends[a].push_back(b);
    }
    vector<bool> picked(n+1, false);

    int ans = 0;
    DFS(friends, picked, 1, n, 0, ans);
    
    if(ans == n) cout<<ans;
    else cout<<ans + 1;
}