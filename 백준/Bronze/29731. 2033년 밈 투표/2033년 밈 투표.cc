#include <bits/stdc++.h>
using namespace std;

const string says[7] = { "Never gonna give you up",
                            "Never gonna let you down",
                            "Never gonna run around and desert you",
                            "Never gonna make you cry",
                            "Never gonna say goodbye",
                            "Never gonna tell a lie and hurt you",
                            "Never gonna stop"};

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s;
    getline(cin, s); // flush
    for(int i = 0; i < n; ++i)
    {
        getline(cin, s);

        bool has = false;
        for(int j = 0; j < 7 && !has; ++j)
        {
            if(s == says[j]) has = true;
        }

        if(!has)
        {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";
}