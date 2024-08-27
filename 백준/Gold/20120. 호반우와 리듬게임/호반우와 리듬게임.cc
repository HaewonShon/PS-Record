#include <bits/stdc++.h>
using namespace std;

long long dp_noHit[1001]; // i-1을 치고 i를 안치는 경우의 최댓값
long long dp_hit[1001][1001]; // 노트를 치는 경우 - {i번째, 콤보} 에서 최대점수

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    memset(dp_noHit, 0, sizeof(dp_noHit));
    memset(dp_hit, 0, sizeof(dp_hit));

    for(int i = 1; i <= n; ++i)
    {
        long long score;
        cin>>score;

        if(i > 1)
        {
            dp_noHit[i] = INT_MIN;
        }

        for(long long j = 1; j < i; ++j)
        {
            dp_noHit[i] = max(dp_noHit[i], dp_hit[i-1][j]); // 이전 노트를 친 경우중 최대값 찾기
        }
        for(long long j = 1; j <= i; ++j)
        {
            dp_hit[i][j] = dp_hit[i-1][j-1] + score * j;
        }

        dp_hit[i][0] = max(dp_noHit[i], dp_noHit[i-1]);
    }

    long long ans = 0;
    for(int i = 0; i <= n; ++i)
    {
        ans = max(ans, dp_hit[n][i]);
    }
    cout<<ans;
}
