#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 진행중인 과제를 stack에 저장하여 최신순으로 처리하자
vector<string> solution(vector<vector<string>> plans) {
   
    // hh:mm 포맷을 분 단위로 변경
    for(auto& plan : plans)
    {
        string h = plan[1].substr(0, 2);
        string m = plan[1].substr(3);
        int minutes = atoi(h.c_str()) * 60 + atoi(m.c_str());
        plan[1] = to_string(minutes);
        
        if(plan[1].length() < 5)
        {
            plan[1] = std::string(5-plan[1].length(), '0') + plan[1];
        }
    }
    
    std::sort(plans.begin(), plans.end(), [](auto& p1, auto& p2){ return p1[1] < p2[1]; });
    
    int currentTime = 0;
    std::stack<pair<std::string, int>> st; // {name, remaining time}
    
    vector<string> answer;
    
    for(int i = 0; i < plans.size(); ++i)
    {
        int planStartTime = atoi(plans[i][1].c_str());
        int requiredTime = atoi(plans[i][2].c_str());
        int timeBeforeStart = planStartTime - currentTime;
        
        while(!st.empty() && timeBeforeStart > 0)
        {
            auto p = st.top();
            st.pop();
            
            if(p.second > timeBeforeStart)
            {
                p.second -= timeBeforeStart;
                st.push(p);
                break;
            }
            else
            {
                timeBeforeStart -= p.second;
                answer.push_back(p.first);
            }
        }
        st.push({plans[i][0], requiredTime});
        currentTime = planStartTime;
    }
    
    while(!st.empty())
    {
        answer.push_back(st.top().first);
        st.pop();
    }
    
    return answer;
}