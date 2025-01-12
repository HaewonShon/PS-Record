#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int characters[26] = {0};

    string name;
    cin>>name;

    for(char c : name)
    {
        ++characters[c-'A'];
    }

    char middle = 0;

    string ans;
    for(int i = 0; i < 26; ++i)
    {
        while(characters[i] >= 2)
        {
            characters[i] -= 2;
            ans += 'A' + i;
        }

        if(characters[i] == 1)
        {
            if(middle != 0)
            {
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
            else
            {
                middle = 'A' + i;
            }
        }
    }

    if(middle != 0)
    {
        cout<<ans<<middle;
        reverse(ans.begin(), ans.end());
        cout<<ans;
    }
    else
    {
        cout<<ans;
        reverse(ans.begin(), ans.end());
        cout<<ans;
    }
}