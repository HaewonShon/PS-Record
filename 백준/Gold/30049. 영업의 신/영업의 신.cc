#include <bits/stdc++.h>
using namespace std;

struct Store
{
    map<int, int> record; // 직원들 기록
    int bestRecord = -1; // 현재 최고 매출/직원
    int bestMember = -1;
};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<Store> stores(m+1);
    vector<int> required(n+1, k); // 영업왕이 되기까지 필요한 매장 수

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            int store, init;
            cin>>store>>init;
            stores[store].record[i] = init;
        }
    }

    int ans = 0;

    // 초기 상태
    for(int i = 1; i <= m; ++i)
    {
        for(auto p : stores[i].record)
        {
            if(p.second > stores[i].bestRecord)
            {
                stores[i].bestRecord = p.second;
                stores[i].bestMember = p.first;
            }
        }

        if(stores[i].bestMember != -1)
        {
            if(--required[stores[i].bestMember] == 0)
            {
                ++ans;
            }
        }
    }

    int q;
    cin>>q;

    while(q--)
    {
        int member, storeNum, record;
        cin>>member>>storeNum>>record;

        stores[storeNum].record[member] += record;
        if(stores[storeNum].record[member] > stores[storeNum].bestRecord)
        {
            // 기존 영업왕 취소
            if(stores[storeNum].bestMember != -1)
            {
                if(required[stores[storeNum].bestMember]++ == 0)
                {
                    --ans;
                }
            }

            stores[storeNum].bestRecord = stores[storeNum].record[member];
            stores[storeNum].bestMember = member;
            if(--required[stores[storeNum].bestMember] == 0)
            {
                ++ans;
            }
        }

        cout<<ans<<"\n";        
    }
}