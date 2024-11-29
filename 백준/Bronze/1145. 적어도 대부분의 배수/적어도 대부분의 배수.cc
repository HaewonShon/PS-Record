#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> nums(5);
    for(int i = 0; i < 5; ++i) cin>>nums[i];

    for(int i = 1;; ++i)
    {
        int count = 0;
        for(int num : nums)
        {
            if(i % num == 0) ++count;
        }
        if(count >= 3)
        {
            cout<<i;
            break;
        }
    }
}