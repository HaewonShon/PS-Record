#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    if(n <= 2)
    {
        cout<<1;
        return 0;
    }

    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    int i, j, ans = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if(v[i] == sorted[j])
            {
                sorted[j] = INT_MAX; // 정렬됨
                break;
            }
        }

        if(j == 0 && sorted[1] != INT_MAX)
        {
            ++ans;
        }
        else if(j == n-1 && sorted[n-2] != INT_MAX)
        {
            ++ans;
        }
        else if(sorted[j-1] != INT_MAX && sorted[j+1] != INT_MAX) // 인접한 수가 모두 정렬이 안되어있음-> 새 덱 생성
        {
            ++ans;
        }
    }

    cout << ans;
}   