#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer;
    set<string> wordSet;
    int len = words.size();
    
    for(int i = 1; i <= len; ++i)
    {
        string& word = words[i-1];
        if(wordSet.find(word) != wordSet.end())
        {
            answer.push_back((i % n) == 0 ? n : (i % n));
            answer.push_back((i % n) == 0 ? i / n : i / n + 1);
            return answer;
        }
        else if(i > 1 && words[i-2].back() != word.front())
        {
            answer.push_back((i % n) == 0 ? n : (i % n));
            answer.push_back((i % n) == 0 ? i / n : i / n + 1);
            return answer;
        }
        else
        {
            wordSet.insert(word);
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}