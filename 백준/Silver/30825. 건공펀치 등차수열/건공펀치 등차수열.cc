#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<unsigned long long> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    unsigned long long ans = 0;
    for(int i = 0; i < n-1; ++i)
    {
        if(v[i] + k < v[i+1])
        {
            ans += (v[i+1] - v[i] - k) * (i + 1); // 이전 것들 전부 올려야 함
            v[i] = v[i+1] - k;
        }
        else if(v[i] + k > v[i+1])
        {
            ans += v[i] + k - v[i+1];
            v[i+1] = v[i] + k;
        }
    }

    cout<<ans;
}
