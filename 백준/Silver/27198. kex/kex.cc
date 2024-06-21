#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>& v, int n, int k)
{
    if(k == 1 && v[0] != 0) return 0;

    int l = 0;
    int r = 2 * 1e9;

    int result = -1;

    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        int res = (upper_bound(v.begin(), v.end(), mid) - v.begin()) + (k - 1);

        if(res == mid)
        {
            result = mid;
            r = mid - 1;
        }
        else
        {     
            if(res < mid)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }   
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    while(q--)
    {
        int k;
        cin>>k;

        if(k > v.back())
        {
            cout<<n + (k - 1)<<" ";
        }
        else
        {
            cout<<Search(v, n, k)<<" ";
        }
    }
}