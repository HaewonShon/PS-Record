#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>edges[i][j];
        }
    }

    vector<int> unions(n, -1);
    int group = 0;

    for(int i = 0; i < n; ++i)
    {
        // BFS로 union 찾기
        if(unions[i] == -1)
        {
            queue<int> q;

            unions[i] = group++;
            q.push(i);

            while(!q.empty())
            {
                int next = q.front();
                q.pop();
                
                for(int j = 0; j < n; ++j)
                {
                    if(edges[next][j] == 1 && unions[j] == -1)
                    {
                        unions[j] = unions[i];
                        q.push(j);
                    }
                }
            }
        }
    }

    int begin;
    cin>>begin;

    for(int i = 1; i < m; ++i)
    {
        int next;
        cin>>next;
        if(unions[begin-1] != unions[next-1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
