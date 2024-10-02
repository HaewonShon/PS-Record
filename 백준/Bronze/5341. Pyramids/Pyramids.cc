#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    while(n != 0)
    {
        cout<<n*(n+1)/2<<"\n";
        cin>>n;
    }
}
