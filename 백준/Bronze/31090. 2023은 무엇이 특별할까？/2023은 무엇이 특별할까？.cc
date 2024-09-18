#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int last2Digits = n % 100;
        if((n + 1) % last2Digits == 0)
        {
            cout<<"Good\n";
        }
        else
        {
            cout<<"Bye\n";
        }
    }
}