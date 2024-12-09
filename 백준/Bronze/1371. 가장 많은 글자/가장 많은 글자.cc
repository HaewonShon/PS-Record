#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> count(26, 0);
    string line;
    while(!getline(cin, line).eof())
    {
        for(char c : line)
        {
            ++count[c-'a'];
        }
    }
    
    vector<char> ans;
    ans.push_back('a');
    int ansCount = count[0];

    for(int i = 1; i < 26; ++i)
    {
        if(count[i] > ansCount)
        {
            ans.clear();
            ansCount = count[i];
            ans.push_back('a' + i);
        }
        else if(count[i] == ansCount)
        {
            ans.push_back('a' + i);
        }
    }

    if(ansCount > 0)
    {
        for(char c : ans)
        {
            cout<<c;
        }
    }
}
