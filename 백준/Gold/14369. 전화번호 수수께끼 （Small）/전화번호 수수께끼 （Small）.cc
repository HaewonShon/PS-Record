#include <bits/stdc++.h>
using namespace std;

string numbers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
                        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int tc = 1;
    while(t--)
    {
        string s;
        cin>>s;

        int charCount[26] = {0};
        for(char c : s)
        {
            ++charCount[c - 'A'];
        }

        string ans;

        // ZERO
        while(charCount['Z'-'A'] > 0)
        {
            ans += '0';
            --charCount['Z'-'A'];
            --charCount['E'-'A'];
            --charCount['R'-'A'];
            --charCount['O'-'A'];
        }

        // TWO
        while(charCount['W'-'A'] > 0)
        {
            ans += '2';
            --charCount['T'-'A'];
            --charCount['W'-'A'];
            --charCount['O'-'A'];
        }

        // SIX
        while(charCount['X'-'A'] > 0)
        {
            ans += '6';
            --charCount['S'-'A'];
            --charCount['I'-'A'];
            --charCount['X'-'A'];
        }

        // EIGHT
        while(charCount['G'-'A'] > 0)
        {
            ans += '8';
            --charCount['E'-'A'];
            --charCount['I'-'A'];
            --charCount['G'-'A'];
            --charCount['H'-'A'];
            --charCount['T'-'A'];
        }

        // THREE
        while(charCount['H'-'A'] > 0)
        {
            ans += '3';
            --charCount['T'-'A'];
            --charCount['H'-'A'];
            --charCount['R'-'A'];
            --charCount['E'-'A'];
            --charCount['E'-'A'];
        }
        
        // FOUR
        while(charCount['R'-'A'] > 0)
        {
            ans += '4';
            --charCount['F'-'A'];
            --charCount['O'-'A'];
            --charCount['U'-'A'];
            --charCount['R'-'A'];
        }
        
        // FIVE
        while(charCount['F'-'A'] > 0)
        {
            ans += '5';
            --charCount['F'-'A'];
            --charCount['I'-'A'];
            --charCount['V'-'A'];
            --charCount['E'-'A'];
        }
        
        // SEVEN
        while(charCount['V'-'A'] > 0)
        {
            ans += '7';
            --charCount['S'-'A'];
            --charCount['E'-'A'];
            --charCount['V'-'A'];
            --charCount['E'-'A'];
            --charCount['N'-'A'];
        }

        // ONE
        while(charCount['O'-'A'] > 0)
        {
            ans += '1';
            --charCount['O'-'A'];
            --charCount['N'-'A'];
            --charCount['E'-'A'];
        }
        
        // NINE
        while(charCount['I'-'A'] > 0)
        {
            ans += '9';
            --charCount['N'-'A'];
            --charCount['I'-'A'];
            --charCount['N'-'A'];
            --charCount['E'-'A'];
        }

        sort(ans.begin(), ans.end());

        cout<<"Case #"<<tc++<<": ";
        cout<<ans<<"\n";
    }
}