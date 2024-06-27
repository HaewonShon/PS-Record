#include <bits/stdc++.h>
using namespace std;

void Mapping(string& s, bool isCapital)
{
    char offset = (isCapital ? 'A' : 'a');
    for(char& c : s)
    {
        c = c - offset;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    string s;
    cin>>n;
    cin>>s;

    Mapping(s, true);

    while(n--)
    {
        string s2;
        cin>>s2;
        if(s2.length() > s.length())
        {
            cout<<"-\n";
            continue;
        }

        Mapping(s2, false);
        int i = 0;
        for(; i <= s.length() - s2.length(); ++i)
        {
            vector<int> s1s2(26, -1);
            vector<int> s2s1(26, -1);

            int j = 0;
            for(; j < s2.length(); ++j)
            {
                char c1 = s[i + j];
                char c2 = s2[j];
                if(s2s1[c2] == -1) // s2[j]가 아직 나타나지 않음
                {
                    if(s1s2[c1] != -1) break; // 해당하는 s1[i+j]가 이미 나타남
                    s2s1[c2] = c1;
                    s1s2[c1] = c2;
                }
                else
                {
                    if(s1s2[c1] != c2 || s2s1[c2] != c1) break;
                }
            }

            if(j == s2.length())
            {
                cout<<i<<"\n";
                break;
            }
        }

        if(i > s.length() - s2.length())
        {
            cout<<"-\n";
        }
    }
}   