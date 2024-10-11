#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    if(n == 1)
    {
        cout<<1<<"\n";
        cout<<"1 1";
        return 0;
    }
    
    cout<<n*2-2<<"\n";

    for(int i = 1; i <= n; ++i)
    {
        cout<<i<<" "<<1<<"\n";
    }

    for(int i = 2; i <= n-1; ++i)
    {
        cout<<i<<" "<<n<<"\n";
    }
}
