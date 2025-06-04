#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input, target;
    string cleanInput;

    cin>>input>>target;

    for(char c : input)
    {
        if(!(c >= '0' && c <= '9'))
        {
            cleanInput += c;
        }
    }

    cout<<(cleanInput.find(target) != string::npos);
}
    