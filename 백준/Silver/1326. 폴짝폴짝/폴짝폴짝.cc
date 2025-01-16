#include <bits/stdc++.h>
using namespace std;

int visited[10001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(visited, 0, sizeof(visited));

    int n;
    cin>>n;

    vector<int> spot(n+1);
    for(int i = 1; i <= n; ++i) cin>>spot[i];

    int a, b;
    cin>>a>>b;

    queue<int> q;
    q.push(a);
    visited[a] = 1;

    while(!q.empty())
    {
        int pos = q.front();
        q.pop();

        int move = spot[pos];

        int nextPos = pos + move;
        while(nextPos <= n)
        {
            if(nextPos == b)
            {
                cout<<visited[pos];
                return 0;
            }

            if(visited[nextPos] == 0)
            {
                visited[nextPos] = visited[pos] + 1;
                q.push(nextPos);
            }
            nextPos += move;
        }
        nextPos = pos - move;
        while(nextPos > 0)
        {      
            if(nextPos == b)
            {
                cout<<visited[pos];
                return 0;
            }

            if(visited[nextPos] == 0)
            {
                visited[nextPos] = visited[pos] + 1;
                q.push(nextPos);
            }
            nextPos -= move;
        }
    }    

    cout<<-1;
}