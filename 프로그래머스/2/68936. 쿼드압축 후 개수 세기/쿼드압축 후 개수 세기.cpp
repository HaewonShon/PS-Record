#include <string>
#include <vector>

using namespace std;

int compress(const vector<vector<int>>& arr, vector<int>& answer, int i, int j, int size)
{
    if(size == 1)
    {
        ++answer[arr[i][j]];
        return arr[i][j]; 
    }
    
    
    int halfSize = size / 2;
    
    int res[4] = {
    compress(arr, answer, i, j,halfSize),
    compress(arr, answer, i + halfSize, j, halfSize),
    compress(arr, answer, i + halfSize, j + halfSize, halfSize),
    compress(arr, answer, i, j + halfSize, halfSize)};
    
    if(res[0] == 0 && res[1] == 0 && res[2] == 0 && res[3] == 0)
    {
        answer[0] -= 3;
        return 0;
    }
    else if(res[0] == 1 && res[1] == 1 && res[2] == 1 && res[3] == 1)
    {
        answer[1] -= 3;
        return 1;
    }
    
    return -1;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    
    int res = compress(arr, answer, 0, 0, arr.size());
    
    //if(res == 0) ++answer[0];
    //else if(res == 1) ++answer[1];
    
    return answer;
}