#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    ~Trie()
    {
        for(int i = 0; i < 26; ++i)
        {
            if(next[i])
            {
                delete next[i];
            }
        }
    }

    Trie* next[26] = {nullptr};
};

void Put(const string& s, int index, Trie* trie)
{
    if(index == s.length()) return;

    char c = s[index];
    if(!trie->next[c-'a'])
    {
        trie->next[c-'a'] = new Trie();
    }
    Put(s, index+1, trie->next[c-'a']);
}

bool Search(const string& s, int index, Trie* trie)
{
    if(index == s.length()) return true;

    char c = s[index];
    if(!trie->next[c-'a'])
    {
        return false;
    }
    else
    {
        return Search(s, index+1, trie->next[c-'a']);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    Trie* trie = new Trie();
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin>>s;
        Put(s, 0, trie);
    }

    int ans = 0;
    while(m--)
    {
        string prefix;
        cin>>prefix;

        if(Search(prefix, 0, trie))
        {
            ++ans;
        }
    }
    cout<<ans;
}
