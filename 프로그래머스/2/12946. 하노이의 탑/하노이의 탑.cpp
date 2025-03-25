#include <string>
#include <vector>

using namespace std;

void MoveTower(vector<vector<int>>& answer, int from, int to, int sub, int height)
{
    if(height == 1)
    {
        answer.push_back({from, to});
        return;
    }
    
    MoveTower(answer, from, sub, to, height-1);
    answer.push_back({from, to});
    MoveTower(answer, sub, to, from, height-1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    MoveTower(answer, 1, 3, 2, n);
    
    return answer;
}