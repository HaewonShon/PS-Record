#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie* trie[26] = { nullptr };
    int count = 0;
};

void DFS(vector<string>& board, int n, int m, int r, int c, int depth, Trie* parent)
{
    char character = board[r][c];
    if(parent->trie[character - 'a'] == nullptr)
    {
        parent->trie[character - 'a'] = new Trie;
    }
    parent->trie[character - 'a']->count += 1;

    if(depth == 5) return;

    for(int rOffset = -1; rOffset <= 1; ++rOffset)
    {
        for(int cOffset = -1; cOffset <= 1; ++cOffset)
        {
            if(rOffset == 0 && cOffset == 0) continue;
            DFS(board, n, m, (r + rOffset + n) % n, (c + cOffset + m) % m, depth + 1, parent->trie[ character-'a']);
        }
    }
}

int Search(Trie* trie, const string& s, int index)
{
    if(trie == nullptr) return 0;

    if(index == s.length())
    {
        return trie->count;
    }

    return Search(trie->trie[s[index] - 'a'], s, index + 1);
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<string> board(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>board[i];
    }
    
    Trie trie;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            DFS(board, n, m, i, j, 1, &trie);
        }
    }

    while(k--)
    {
        string s;
        cin>>s;

        cout<<Search(&trie, s, 0)<<"\n";
    }
}