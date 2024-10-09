#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    string k;
    cin>>n>>k;

    int odds = 0;
    int evens = 0;
    for(char c : k)
    {
        if((c-'0') % 2 == 1) ++odds;
        else ++evens;
    }

    if(odds == evens)
    {
        cout<<-1;
    }
    else if(odds > evens)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
