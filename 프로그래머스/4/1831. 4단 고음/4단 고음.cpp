#include <cmath>
#include <set>
#include <iostream>

using namespace std;

set<std::string> answerSet;

const int MAX_PLUS_COUNT = 38; // INT_MAX < 3^20

void Search(int curr, int asteriskCount, int plusCount, std::string s)
{
    if(curr == 1)
    {
        if(s[0] == '*' && (asteriskCount * 2 == plusCount)) 
        {
            answerSet.insert(s);
        }
        return;
    }
    
    if(curr <= 0 || plusCount > MAX_PLUS_COUNT || asteriskCount * 2 > plusCount) return;
    
    
    while(curr % 3 > 0)
    {
        --curr;
        ++plusCount;
        s = '+' + s;
    }
    
    Search(curr / 3, asteriskCount + 1, plusCount, '*' + s);
    Search(curr - 3, asteriskCount, plusCount + 3, "+++" + s);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    answerSet.clear();
    
    Search(n, 0, 0, "");
    
    return answerSet.size();
}