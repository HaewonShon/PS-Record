#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> v(n+1, 0);

    for(int i = 1; i <= n; ++i)
    {
        cin>>v[i];
        v[i] += v[i-1];
    }

    int max = 0, count = 0;

    for(int i = x; i <= n; ++i)
    {
        if(v[i] - v[i-x] > max)
        {
            max = v[i] - v[i-x];
            count = 1;
        }
        else if(v[i] - v[i-x] == max)
        {
            ++count;
        }
    }

    if(max == 0)
    {
        cout<<"SAD";
    }
    else
    {
        cout<<max<<"\n"<<count;
    }
}