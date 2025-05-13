#include <string>
#include <vector>

using namespace std;

int DFS(int toOpen, int opened)
{
    if(toOpen == 0) return 1;
    
    int res = 0;
    if(opened > 0)
    {
        res += DFS(toOpen, opened - 1);
    }
    res += DFS(toOpen - 1, opened + 1);
    
    return res;
}

int solution(int n) {
    int answer = DFS(n, 0);
    return answer;
}