#include <bits/stdc++.h>
using namespace std;

long long CharToInt(char c)
{
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    }

    switch(c)
    {
        case 'A': return 10;
        case 'C': return 11;
        case 'D': return 12;
        case 'E': return 13;
        case 'F': return 14;
        case 'H': return 15;
        case 'J': return 16;
        case 'K': return 17;
        case 'L': return 18;
        case 'M': return 19;
        case 'N': return 20;
        case 'P': return 21;
        case 'R': return 22;
        case 'T': return 23;
        case 'V': return 24;
        case 'W': return 25;
        case 'X': return 26;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int k;
        string s;
        cin>>k>>s;

        for(char& c : s)
        {
            switch(c)
            {
                case 'B': c = '8'; break;
                case 'G': c = 'C'; break;
                case 'I': c = '1'; break;
                case 'O': c = '0'; break;
                case 'Q': c = '0'; break;
                case 'S': c = '5'; break;
                case 'U': c = 'V'; break;
                case 'Y': c = 'V'; break;
                case 'Z': c = '2'; break;
            }
        }

        int multiplierForDigit[8] = {2, 4, 5, 7, 8, 10, 11, 13};

        int total = 0;
        for(int i = 0; i < 8; ++i)
        {
            total += CharToInt(s[i]) * multiplierForDigit[i];
        }

        total %= 27;
        
        cout<<k<<" ";

        if(total == CharToInt(s.back()))
        {
            long long res = 0;
            long long multiplier = 1;

            for(int i = 1; i <= 8; ++i)
            {
                res += CharToInt(s[8-i]) * multiplier;
                multiplier *= 27;
            }

            cout<<res<<"\n";
        }
        else
        {
            cout<<"Invalid\n";
        }
    }
}