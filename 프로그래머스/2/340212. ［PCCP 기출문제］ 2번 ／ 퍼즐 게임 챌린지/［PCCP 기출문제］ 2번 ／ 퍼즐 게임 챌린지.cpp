#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;
    int n = diffs.size();
    
    // 이분탐색으로 가능한 최저 숙련도 탐색
    int l = 1, r = 100000;
    while(l <= r)
    {
        long long res = 0;
        int level = l + (r-l) / 2;
        for(int i = 0; i < n; ++i)
        {
            if(level >= diffs[i])
            {
                res += times[i];
            }
            else
            {
                long long levelDiff = diffs[i] - level;
                levelDiff *= (times[i] + times[i-1]);
                res += levelDiff + times[i];
            }
        }
        
        if(res <= limit)
        {
            answer = level;
            r = level - 1;
        }
        else
        {
            l = level + 1;
        }
    }
    
    return answer;
}