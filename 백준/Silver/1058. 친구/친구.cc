#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> friends(n);
    for(int i=0; i<n; i++) {
        cin>>friends[i];
    }

    int maxFriendCount = 0;

    for(int i = 0; i < n; ++i)
    {
        int friendCount = 0;
        vector<bool> visited(n, false);
        visited[i] = true;

        queue<int> q;
        // 1-friend
        for(int j = 0; j < n; ++j)
        {
            if(friends[i][j] == 'Y')
            {
                visited[j] = true;
                friendCount++;
                q.push(j);
            }
        }
        
        // 2-friend
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int j = 0; j < n; ++j)
            {
                if(friends[curr][j] == 'Y' && !visited[j])
                {
                    visited[j] = true;
                    friendCount++;
                }
            }
        }

        maxFriendCount = max(maxFriendCount, friendCount);
    }

    cout<<maxFriendCount;
}   