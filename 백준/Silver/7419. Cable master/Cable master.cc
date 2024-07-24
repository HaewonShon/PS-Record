#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>& cables, int k)
{
    int l = 1;
    int r = 10000000;

    int res = -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        int possibleCount = 0;
        for(int cable : cables)
        {
            possibleCount += cable / mid;
        }

        if(possibleCount >= k)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> cables(n);
    for(int i = 0; i < n; ++i)
    {
        int meter;
        char dot;
        int centimeter;
        cin>>meter>>dot>>centimeter;
        cables[i] = meter * 100 + centimeter;
    }

    float ans = float(Search(cables, k)) / 100;
    cout<<fixed;
    cout.precision(2);
    if(ans < 0)
    {
        cout<<"0.00";
    }
    else
    {
        cout<<ans;
    }

}