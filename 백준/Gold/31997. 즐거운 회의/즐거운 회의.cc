#include <bits/stdc++.h>
using namespace std;

vector<int> joinList[200001];
vector<int> leftList[200001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, t;
    cin>>n>>m>>t;

    for(int i = 0; i < n; ++i)
    {
        int join, left;
        cin>>join>>left;
        joinList[join].push_back(i+1);
        leftList[left].push_back(i+1);
    }

    vector<vector<int>> friends(n+1);

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    vector<bool> isInMeeting(n+1, false);

    int ans = 0;
    for(int i = 0; i < t; ++i)
    {
        for(int member : leftList[i])
        {
            isInMeeting[member] = false;

            for(int fnd : friends[member])
            {
                if(isInMeeting[fnd] == true)
                {
                    --ans;
                }
            }
        }

        for(int member : joinList[i])
        {
            isInMeeting[member] = true;

            for(int fnd : friends[member])
            {
                if(isInMeeting[fnd] == true)
                {
                    ++ans;
                }
            }
        }

        cout<<ans<<"\n";
    }
}