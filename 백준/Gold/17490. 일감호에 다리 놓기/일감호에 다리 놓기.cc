#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    long long n, m, k;
    cin>>n>>m>>k;

    if(m <= 1)
    {
        cout<<"YES";
        return 0;
    }

    vector<int> required(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin>>required[i];
    }

    vector<pair<int, int>> onConstruction(m);
    for(int i = 0; i < m; ++i)
    {
        cin>>onConstruction[i].first>>onConstruction[i].second;
        if(onConstruction[i].first > onConstruction[i].second) 
        {
            if(!(onConstruction[i].first == n && onConstruction[i].second == 1))
            {
                swap(onConstruction[i].first, onConstruction[i].second);
            }
        }
    }

    sort(onConstruction.begin(), onConstruction.end());

    vector<int> requiredForIntervals;
    int begin = 1;
    for(int i = 0; i < m; ++i)
    {
        requiredForIntervals.push_back(required[begin]);
        while(++begin <= onConstruction[i].first)
        {
            requiredForIntervals.back() = min(requiredForIntervals.back(), required[begin]);
        }
    }

    // 1과 연결된 N, N-1.. 확인
    if(onConstruction.back().second != 1)
    {
        int back = n;
        while(back >= onConstruction.back().second)
        {
            requiredForIntervals.front() = min(requiredForIntervals.front(), required[back]);
            --back;
        }
    }

    long long total = accumulate(requiredForIntervals.begin(), requiredForIntervals.end(), (long long)0);
    
    if(total <= k)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}