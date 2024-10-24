#include <bits/stdc++.h>
using namespace std;

bool has[1000];
bool hastwo[1000];

int GetSumOfDigits(int val)
{
    int res = 0;
    while(val > 0)
    {
        res += val % 10;
        val /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(has, 0, sizeof(has));  
    memset(hastwo, 0, sizeof(hastwo));    

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;
        if(has[val]) hastwo[val] = true;
        has[val] = true;
    }

    vector<int> vals;
    for(int i = 1; i < 1000; ++i)
    {
        if(has[i]) vals.push_back(i);
        if(hastwo[i]) vals.push_back(i);
    }

    int ans = 0;

    int size = vals.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = i+1; j < size; ++j)
        {
            int multiply = vals[i] * vals[j];
            ans = max(ans, GetSumOfDigits(multiply));
        }
    }
    cout<<ans;
}