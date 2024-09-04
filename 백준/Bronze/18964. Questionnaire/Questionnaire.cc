#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    int odds = 0, evens = 0;
    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;

        if(val % 2 == 1) ++odds;
        else ++evens;
    }

    if(odds < evens)
    {
        cout<<"2 0";
    }
    else
    {
        cout<<"2 1";
    }
}
