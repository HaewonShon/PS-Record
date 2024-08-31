#include <bits/stdc++.h>
using namespace std;

int DFS(const vector<vector<int>>& info, int m, int n, int mask, int start, int selected)
{
    int res = INT_MAX;
    for(int i = start; i < m; ++i)
    {
        int partialMask = 0;
        for(int prob : info[i])
        {
            partialMask |= (1 << (prob-1));
        }
        partialMask ^= mask; // 이전 마스크와 중복되지 않는 부분만 남기기

        int newMask = mask | partialMask;
        if(newMask == (1 << n) - 1) // 조건 만족
        {
            return selected + 1;
        }

        res = min(res, DFS(info, m, n, newMask, i + 1, selected + 1));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> info(m);
    for(int i = 0; i < m; ++i)
    {
        int count;
        cin>>count;
        info[i] = vector<int>(count);
        for(int j = 0; j < count; ++j)
        {
            cin>>info[i][j];
        }
    }

    int res = DFS(info, m, n, 0, 0, 0);
    if(res == INT_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<res;
    }
}
