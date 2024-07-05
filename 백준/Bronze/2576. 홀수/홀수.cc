#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n = 7;
    int sum = 0;
    int minVal = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;
        if(val % 2 == 1)
        {
            sum += val;
            minVal = min(val, minVal);
        }
    }

    if(sum == 0)
    {
        cout<<-1;
    }
    else
    {
        cout<<sum<<"\n"<<minVal;
    }
}