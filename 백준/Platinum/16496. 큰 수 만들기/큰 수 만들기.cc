#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<string> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    sort(v.begin(), v.end(), [](string& v1, string& v2)
    {
        return (v1 + v2) > (v2 + v1);
    });

    if(v[0].front() == '0')
    {
        cout<<0;
    }
    else
    {
        for(string& s : v)
        {
            cout<<s;
        }
    }
}