#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    int c1, c2;
    cin>>c1>>c2;

    // p
    vector<int> P(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>P[i];
    }

    // q
    vector<int> Q(m);
    for(int i = 0; i < m; ++i)
    {
        cin>>Q[i];
    }

    // strategy: 정렬 후 투 포인터 이용하여 두 수를 근접하게 유지하고, 가장 거리가 가까운 경우를 찾는다
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    int Pindex = 0;
    int Qindex = 0;

    int minDiff = INT_MAX;
    int minCount = 0;
    while(Pindex < n && Qindex < m)
    {
        int diff = abs(P[Pindex] - Q[Qindex]);
        if(diff < minDiff)
        {
            minCount = 1;
            minDiff = diff;
        }
        else if(diff == minDiff)
        {
            ++minCount;
        }

        if(P[Pindex] < Q[Qindex])
        {
            ++Pindex;
        }
        else
        {
            ++Qindex;
        }
    }
    cout<<(minDiff + abs(c1 - c2))<<" "<<minCount;
}