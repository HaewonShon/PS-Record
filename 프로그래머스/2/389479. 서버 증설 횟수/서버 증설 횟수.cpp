#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    int currentServerCount = 1;
    queue<pair<int, int>> createdServerQueue; // {createdTime, count}

    for(int i = 0; i < players.size(); ++i)
    {
        while(!createdServerQueue.empty() && createdServerQueue.front().first + k == i)
        {
            currentServerCount -= createdServerQueue.front().second;
            createdServerQueue.pop();
        }
        
        if(players[i] >= currentServerCount * m)
        {
            int remainedPlayerCount = players[i] - (currentServerCount * m - 1);
            int requiredServerCount = remainedPlayerCount / m + ((remainedPlayerCount % m == 0) ? 0 : 1);
            
            createdServerQueue.push({i, requiredServerCount});
            currentServerCount += requiredServerCount;
            answer += requiredServerCount;
        }
    }
    
    
    return answer;
}