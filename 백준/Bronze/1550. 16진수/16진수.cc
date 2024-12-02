#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string hex;
    cin>>hex;

    int res = 0;
    int power = 0;
    for(int index = hex.length() - 1; index >= 0; --index, ++power)
    {
        if(hex[index] >= '0' && hex[index] <= '9') res += (hex[index] - '0') * pow(16, power);
        else res += (hex[index] - 'A' + 10) * pow(16, power);
    } 
    cout<<res;
}