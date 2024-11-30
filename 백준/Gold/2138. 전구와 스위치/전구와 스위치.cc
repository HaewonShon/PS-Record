#include <bits/stdc++.h>
using namespace std;

void Try(string a, const string& b, int n, int& res)
{
    for(int i = 1; i < n-1; ++i)
    {
        if(a[i-1] != b[i-1])
        {
            a[i-1] = (a[i-1] == '0' ? '1' : '0');
            a[i] = (a[i] == '0' ? '1' : '0');
            a[i+1] = (a[i+1] == '0' ? '1' : '0');
            ++res;
        }
    }

    // i == n-1
    if(a[n-2] != b[n-2])
    {
        a[n-2] = (a[n-2] == '0' ? '1' : '0');
        a[n-1] = (a[n-1] == '0' ? '1' : '0');
        ++res;
    }

    if(a[n-1] != b[n-1])
    {
        res = INT_MAX; // failed
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    string a, b;
    cin>>n>>a>>b;

    int res = 0;
    Try(a, b, n, res);

    int ans = res;
    res = 1;
    a[0] = (a[0] == '0' ? '1' : '0');
    a[1] = (a[1] == '0' ? '1' : '0');
    Try(a, b, n, res);

    ans = min(ans, res);
    if(ans == INT_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
}