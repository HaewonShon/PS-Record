#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin>>v[i];

    sort(v.begin(), v.end(), [](string& a, string& b){
        if(a.length() != b.length())
        {
            return a.length() < b.length();
        }
        int aSum = 0;
        int bSum = 0;
        int n = a.length();
        for(int i = 0; i < n; ++i)
        {
            if(a[i] >= '0' && a[i] <= '9') aSum += a[i] - '0';
            if(b[i] >= '0' && b[i] <= '9') bSum += b[i] - '0';
        }

        if(aSum != bSum)
        {
            return aSum < bSum;
        }

        return a < b;
    });   

    for(const string& s : v)
    {
        cout<<s<<"\n";
    }
}