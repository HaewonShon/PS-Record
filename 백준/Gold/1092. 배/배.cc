#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> cranes(n);
    for(int i = 0; i < n; ++i) cin>>cranes[i];

    int m;
    cin>>m;

    vector<int> containers(m);
    for(int i = 0; i < m; ++i) cin>>containers[i];

    sort(cranes.rbegin(), cranes.rend());
    sort(containers.rbegin(), containers.rend());

    if(cranes.front() < containers.front())
    {
        cout<<-1;
        return 0;
    }

    int ans = 0; // 화물 수 / 가용 가능 크레인 수의 최댓값
    
    int craneIndex = 0;
    int containerIndex = 0;

    while(containerIndex < m)
    {
        // 가능한 크레인 수 증가
        while(craneIndex < n-1 && containers[containerIndex] <= cranes[craneIndex + 1])
        {
            ++craneIndex;
        }

        int craneCount = craneIndex + 1;
        int containerCount = containerIndex + 1;

        ans = max(ans, (containerCount / craneCount) + ((containerCount % craneCount) ? 1 : 0));

        ++containerIndex;
    }
    cout<<ans;
    
}