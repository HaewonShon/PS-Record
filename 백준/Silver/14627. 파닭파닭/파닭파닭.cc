#include <bits/stdc++.h>
using namespace std;

int GetPossibleLeakCount(vector<int>& leaks, int length)
{
    int multipleLength = length;
    int res = 0;
    while(multipleLength <= leaks.back())
    {
        res += (leaks.end() - lower_bound(leaks.begin(), leaks.end(), multipleLength));
        multipleLength += length;
    }
    return res;
}

int GetLeakLength(vector<int>& leaks, int requiredNum)
{
    int l = 1;
    int r = leaks.back();

    int res = 0;
    while(l <= r)
    {
        int mid = l + (r-l)/2;

        // 현재 길이로 가능->길이를 늘려본다
        if(GetPossibleLeakCount(leaks, mid) >= requiredNum)
        {
            res = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int s, c;
    cin>>s>>c;

    vector<int> leaks(s);
    for(int i = 0; i < s; ++i)
    {
        cin>>leaks[i];
    }

    sort(leaks.begin(), leaks.end());

    int leakLength = GetLeakLength(leaks, c);
    long long totalLength = accumulate(leaks.begin(), leaks.end(), (long long)0);
    
    //cout<<"LeakLength: "<<leakLength<<"\n";
    cout<<totalLength - ((long long)leakLength * c);
}
