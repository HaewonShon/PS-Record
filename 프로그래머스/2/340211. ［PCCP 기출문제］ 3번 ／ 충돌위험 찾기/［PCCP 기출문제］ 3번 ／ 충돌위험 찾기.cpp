#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Robot
{
    vector<int> pos;
    int currentTargetRoute = 0;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int x = routes.size();
    vector<Robot> robots(x);
    int routeCount = routes[0].size();
    
    int board[101][101]; // board[i][j] = 현재 {i, j}에 위치한 로봇 수
    memset(board, 0, sizeof(board));
    
    for(int i = 0; i < x; ++i)
    {
        robots[i] = { points[routes[i][0]-1], 1};
        if(++board[robots[i].pos[0]][robots[i].pos[1]] == 2) ++answer;
    }  
    
    int movedRobotCount = 0;
    do
    {
        memset(board, 0, sizeof(board));
        movedRobotCount = 0;
        
        for(int i = 0; i < x; ++i)
        {
            Robot& robot = robots[i];
            if(robot.currentTargetRoute == routeCount) continue; // 이미 경로를 완료한 로봇
            
            vector<int> targetPoint = points[routes[i][robot.currentTargetRoute] - 1];
            
            if(robot.pos[0] < targetPoint[0])
            {
                ++robot.pos[0];
            }
            else if(robot.pos[0] > targetPoint[0])
            {
                --robot.pos[0];
            }
            else if(robot.pos[1] < targetPoint[1])
            {
                ++robot.pos[1];
            }
            else if(robot.pos[1] > targetPoint[1])
            {
                --robot.pos[1];
            }
            
            if(robot.pos[0] == targetPoint[0] && robot.pos[1] == targetPoint[1])
            {
                ++robot.currentTargetRoute;
            }
            
            if(++board[robot.pos[0]][robot.pos[1]] == 2) ++answer;
            ++movedRobotCount;
        }
    } while(movedRobotCount != 0);
    
    return answer;
}