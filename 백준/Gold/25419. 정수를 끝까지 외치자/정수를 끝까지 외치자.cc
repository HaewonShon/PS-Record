#include <bits/stdc++.h>
using namespace std;

int res[100001]; // 1 == 부르면 이김, 2 == 부르면 짐

int Play(int p, int val, int k, int n)
{
    if(val > n) return -1;
    if(res[val] != 0) return res[val];

    res[val] = 1;
    for(int i = 1; i <= k; ++i)
    {
        if(Play((p + 1) % 2, val + i, k, n) == 1) // 상대 차례에 끝나는 경우가 있음
        {
            res[val] = 2; // 현재 수를 부른다 = 내 패배
            break;
        }
    }
    return res[val];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(res, 0, sizeof(res));

    int n, k;
    cin>>n>>k;

    int val;
    while(cin>>val)
    {
        res[val] = -1;
    }

    while(res[n] == -1) --n; // n = 실질적 방문가능한 마지막 수
    res[n] = 1;

    int i = 1;
    for(; i <= k; ++i) // 첫 방문이 불가한 경우
    {
        if(res[i] != -1) break;
    }
    if(i > k)
    {
        cout<<0;
        return 0;
    }

    for(i = 1; i <= k; ++i)
    {
        if(res[i] == -1) continue;
        
        if(Play(1, i, k, n) == 1) // p1이 이기는 수가 존재함
        {
            cout<<1;
            return 0;
        }
    }
    cout<<0;
}