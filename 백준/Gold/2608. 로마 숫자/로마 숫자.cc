#include <bits/stdc++.h>
using namespace std;

int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string str[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int toInteger(string rome)
{
    int res = 0;

    for(int i = 0; i < 13 && rome.length() > 0; ++i)
    {
        while(rome.substr(0, str[i].length()) == str[i])
        {
            res += val[i];
            rome = rome.substr(str[i].length());
        }
    }

    return res;
}

string toRome(int value)
{
    string res;
    
    for(int i = 0; i < 13; ++i)
    {
        while(value >= val[i])
        {
            res += str[i];
            value -= val[i];
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string a, b;
    cin>>a>>b;

    int res = toInteger(a) + toInteger(b);
    cout<<res<<"\n"<<toRome(res);
}