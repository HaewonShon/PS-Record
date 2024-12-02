#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer(balls.size());
    
    // 벽을 기준으로 데칼코마니시켜 칠때 가장 짧은 거리는? 꼭짓점은 최단거리가 아니므로 고려할 필요가 없다
    for(int i = 0; i < balls.size(); ++i)
    {
        int a = balls[i][0];
        int b = balls[i][1];
        
        int res = 100000000;
        if(startX != a)
        {
            // 윗면에 반사
            res = min(res, (startY + b) * (startY + b) + abs(startX - a) * abs(startX - a)); 

            // 아랫면에 반사
            res = min(res, ((n-startY) + (n-b)) * ((n-startY) + (n-b)) + abs(startX - a) * abs(startX - a));  
        }
        else
        {
            if(startY < b) res = min(res, (startY + b) * (startY + b));
            else res = min(res, (2*n - startY - b) * (2*n - startY - b));
        }
        
        if(startY != b)
        {
            // 왼쪽면에 반사
            res = min(res, (startX + a) * (startX + a) + abs(startY - b) * abs(startY - b));

            // 오른쪽면에 반사
            res = min(res, ((m-startX) + (m-a)) * ((m-startX) + (m-a)) + abs(startY - b) * abs(startY - b));    
        }
        else
        {
            if(startX < a) res = min(res, (startX + a) * (startX + a));
            else res = min(res, (2 * m - startX - a) * (2 * m - startX - a));
        }
        
        answer[i] = res;
    }
    
    return answer;
}