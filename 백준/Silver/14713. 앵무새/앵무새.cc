#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cin.ignore();

    vector<queue<string>> sentences(n);
    for(int i = 0; i < n; ++i)
    {
        string s;
        getline(cin, s);
        while(s.find(' ') != string::npos)
        {
            string word = s.substr(0, s.find(' '));
            sentences[i].push(word);
            s = s.substr(s.find(' ') + 1);
        }
        sentences[i].push(s);
    }

    string L;
    getline(cin, L);
    while(L.find(' ') != string::npos)
    {
        string word = L.substr(0, L.find(' '));
        L = L.substr(L.find(' ') + 1);
        bool foundWord = false;
        for(auto& sentence : sentences)
        {
            if(sentence.empty() == false && sentence.front() == word)
            {
                foundWord = true;
                sentence.pop();
                break;
            }
        }
        
        if(!foundWord)
        {
            cout<<"Impossible";
            return 0;
        }
    }

    // 마지막 단어
    bool foundWord = false;
    for(auto& sentence : sentences)
    {
        if(sentence.empty() == false && sentence.front() == L)
        {
            foundWord = true;
            sentence.pop();
        }
    }

    if(foundWord)
    {
        // 남은 단어가 있는지ㅣ?
        for(auto& sentence : sentences)
        {
            if(sentence.empty() == false)
            {
                cout<<"Impossible";
                return 0;
            }
        }
        cout<<"Possible";
    }
    else
    {
        cout<<"Impossible";
    }
}   