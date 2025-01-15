#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int k;
    cin>>k;

    string ans("AKARAKA");

    for(int i = 2; i <= k; ++i)
    {
        ans += "RAKA";
    }
    cout<<ans;
}