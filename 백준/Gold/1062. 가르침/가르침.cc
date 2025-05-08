#include <bits/stdc++.h>
using namespace std;

int Search(int learntLetters, int k, int index, const vector<int>& words)
{
    if(index > 'z' - 'a' || k == 0)
    {
        int res = 0;
        for(int word : words)
        {
            if((learntLetters & word) == word) ++res;
        }
        return res;
    }

    if(learntLetters & (1 << index))
    {
        return Search(learntLetters, k, index+1, words);
    }
    else
    {
        return max(Search(learntLetters | (1 << index), k-1, index+1, words),
                    Search(learntLetters, k, index+1, words));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    if(k < 5) // anta + tica 불가능
    {
        cout<<0;
        return 0;
    }
    else if(k == 26)
    {
        cout<<n;
        return 0;
    }

    vector<int> words(n, 0);
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin>>s;

        for(char c : s)
        {
            words[i] |= 1 << (c - 'a');
        }
    }

    // 필수 5글자
    int learntLetters = 0;
    learntLetters |= 1 << ('a' - 'a');
    learntLetters |= 1 << ('c' - 'a');
    learntLetters |= 1 << ('i' - 'a');
    learntLetters |= 1 << ('n' - 'a');
    learntLetters |= 1 << ('t' - 'a');
    k -= 5;

    cout<<Search(learntLetters, k, 0, words);
}