#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    long long p;
    cin>>n>>m>>p;

    vector<vector<int>> enemies(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>enemies[i][j];
        }
        sort(enemies[i].begin(), enemies[i].end()); // 전투력순 미리 정렬
    }

    // 1. 지금 가능한 적군은 다 잡는다
    // 2. 사용가능한 아이템이 있으면 사용한다
    // 3. 사용가능한 아이템이 없고 적군을 잡지 못하면 실패한다
    // 4. 남은 아이템은 모두 사용한다
    for(auto stage : enemies)
    {
        int index = 0;
        int items = 0;
        while(index < m && stage[index] == -1)
        {
            ++items;
            ++index;
        }

        while(index < m)
        {
            if(stage[index] <= p)
            {
                p += stage[index];
                ++index;
            }
            else if(items > 0)
            {
                --items;
                p <<= 1;
            }
            else
            {
                cout<<0;
                return 0;
            }
        }

        while(items > 0)
        {
            --items;
            p <<= 1;
        }
    }

    cout<<1;
}
