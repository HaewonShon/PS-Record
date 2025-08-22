#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<queue<int>> q(k + 1);
    vector<int> v(k);

    for(int i = 0; i < k; ++i)
    {
        cin>>v[i];
        q[v[i]].push(i);
    }

    vector<int> onUse(k+1, -1); // 다음 필요 index, -1 == 비사용중
    int onUseCount = 0;
    int ans = 0;

    for(int i = 0; i < k; ++i)
    {
        if(onUse[v[i]] != -1)
        {
            q[v[i]].pop();
            onUse[v[i]] = (q[v[i]].empty()) ? INF : q[v[i]].front();
            continue;
        }

        if(onUseCount == n)
        {
            int toRemove = 0;
            for(int j = 1; j <= k; ++j)
            {
                if(onUse[j] != -1 && onUse[j] > onUse[toRemove])
                {
                    toRemove = j;
                }
            }

            onUse[toRemove] = -1;
            ++ans;
            --onUseCount;
        }

        q[v[i]].pop();
        onUse[v[i]] = (q[v[i]].empty()) ? INF : q[v[i]].front();
        ++onUseCount;
    }

    cout<<ans;
}