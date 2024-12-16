#include <bits/stdc++.h>
using namespace std;

bool isPrime[1002];

string Multiply(const string& s, int times)
{
    string ans;
    int currentVal = 0;

    for(int sIndex = s.length() - 1; sIndex >= 0; --sIndex)
    {
        currentVal += (s[sIndex]-'0') * times;
        ans = char((currentVal % 10) + '0') + ans;
        currentVal /= 10;
    }
    if(currentVal > 0)
    {
        ans = to_string(currentVal) + ans;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i <= 1001; ++i)
    {
        if(isPrime[i])
        {
            int j = i + i;
            while(j <= 1001)
            {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    string s;
    while(cin>>s)
    {
        int n = s.length() + 1;
        if(!isPrime[n])
        {
            cout<<s<<" is not cyclic\n";
            continue;
        }

        bool isCyclic = true;
        string res = Multiply(s, n);
        for(char c : res)
        {
            if(c != '9')
            {
                isCyclic = false;
                break;
            }
        }

        if(isCyclic)
        {
            cout<<s<<" is cyclic\n";
        }
        else
        {
            cout<<s<<" is not cyclic\n";
        }
    }
}