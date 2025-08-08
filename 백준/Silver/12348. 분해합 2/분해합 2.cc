#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;

    string s = to_string(n);

    for(long long val = max((size_t)1, (size_t)(n - s.length() * 9)); val < n; ++val)
    {
        string str = to_string(val);
        long long sum = 0;
        for(char c : str) sum += c - '0';
        if(val + sum == n)
        {
            cout<<val;
            return 0;
        }
    }
    cout<<0;
}