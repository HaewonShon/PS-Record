#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin>>s;

    sort(s.begin(), s.end());

    if(s == "123"
        || s == "456"
        || s == "789"
        || s == "147"
        || s == "258"
        || s == "369"
        || s == "058")
    {
        cout<<"Unlocked";
    }
    else
    {
        cout<<"Locked";
    }

}