#include <bits/stdc++.h>
using namespace std;

int visited[3601]; // 0~3600 seconds

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n, time;
        cin>>n>>time;

        vector<int> buttons(n);
        for(int i = 0; i < n; ++i)
        {
            cin>>buttons[i];
        }
        sort(buttons.begin(), buttons.end());
        bool hasNegativeButton = false;
        if(buttons[0] < 0) hasNegativeButton = true;

        memset(visited, -1, sizeof(visited));

        visited[0] = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(curr == time) break;
            if(!hasNegativeButton && curr > time) continue;

            for(int button : buttons)
            {
                int next = curr + button;
                if(next > 0)
                {
                    next = min(3600, next);
                    if(visited[next] == -1)
                    {
                        visited[next] = visited[curr] + 1;
                        q.push(next);
                    }
                }
            }
        }

        if(visited[time] != -1) cout<<visited[time]<<" 0\n";
        else
        {
            for(int i = time + 1; i <= 3600; ++i)
            {
                if(visited[i] != -1)
                {
                    cout<<visited[i]<<" "<<i-time<<"\n";
                    break;
                }
            }
        }
    }
}
