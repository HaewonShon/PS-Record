#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    for(int i = 1; i <= n; ++i)
    {
        int lineStartIndex = n-i;
        for(int j = 0; j < lineStartIndex; ++j)
        {
            cout<<" ";
        }
        for(int j = 0; j < 2*i-1; ++j)
        {
            if(j % 2 == 0)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}