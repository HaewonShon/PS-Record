#include <string>
#include <vector>
#include <set>

#include <iostream>

using namespace std;

struct Word
{
    string word;
    int begin;
    int end;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    vector<Word> words;
    
    int word_begin_index = message.find_first_not_of(' ');
    message = message.substr(word_begin_index);
    
    while(!message.empty())
    {
        if(message.find_first_of(' ') == std::string::npos)
        {
            Word new_word;
            new_word.word = message;
            new_word.begin = word_begin_index;
            new_word.end = word_begin_index + new_word.word.length() - 1;
            words.push_back(new_word);
            break;
        }
        
        Word new_word;
        new_word.word = message.substr(0, message.find_first_of(' '));
        new_word.begin = word_begin_index;
        new_word.end = word_begin_index + new_word.word.length() - 1;
        
        words.push_back(new_word);
        word_begin_index = new_word.end + 2;
        message = message.substr(message.find_first_of(' ') + 1);
    }

    set<string> spoiler_word;
    set<string> non_spoiler_word;
    
    int spoiler_index = 0;
    for(Word word : words)
    {
        cout<<"word: "<<word.word<<"\n";
        
        while(spoiler_index < spoiler_ranges.size()
             && spoiler_ranges[spoiler_index][1] < word.begin)
        {
            ++spoiler_index;
        }
            
            
        if(spoiler_index >= spoiler_ranges.size())
        {
            non_spoiler_word.insert(word.word);
            continue;
        }
        
        auto spoiler_range = spoiler_ranges[spoiler_index];
        if(spoiler_range[0] > word.end || spoiler_range[1] < word.begin)
        {
            non_spoiler_word.insert(word.word);
        }
        else
        {
            spoiler_word.insert(word.word);
        }
    }
    
    for(string s : spoiler_word)
    {
        if(non_spoiler_word.find(s) == non_spoiler_word.end())
        {
            cout<<s<<"\n";
            ++answer;
        }
    }
    
    return answer;
}