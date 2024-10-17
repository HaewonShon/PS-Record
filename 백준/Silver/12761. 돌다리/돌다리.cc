#include <bits/stdc++.h>
using namespace std;

int visited[100001]; // 방문 차례. 0 = 방문안함

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int a, b, n, m;
    cin>>a>>b>>n>>m;

    memset(visited, 0, sizeof(visited));
    int offset[6] = {-1, 1, -a, a, -b, b};

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        int turn = visited[curr] + 1;
        q.pop();

        for(int i = 0; i < 6; ++i)
        {
            if(curr + offset[i] < 0 || curr + offset[i] > 100000) continue;
            if(visited[curr + offset[i]] != 0) continue;

            if(curr + offset[i] == m)
            {
                cout<<turn-1;
                return 0;
            }

            visited[curr + offset[i]] = turn;
            q.push(curr + offset[i]);
        }

        if(curr * a <= 100000 && visited[curr * a] == 0)
        {
            if(curr * a == m)
            {
                cout<<turn-1;
                return 0;
            }

            visited[curr * a] = turn;
            q.push(curr * a);
        }
        
        if(curr * b <= 100000 && visited[curr * b] == 0)
        {
            if(curr * b == m)
            {
                cout<<turn-1;
                return 0;
            }

            visited[curr * b] = turn;
            q.push(curr * b);
        }
    }
}