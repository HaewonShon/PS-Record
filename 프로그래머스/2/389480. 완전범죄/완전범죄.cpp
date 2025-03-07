#include <string>
#include <cstring> // memset
#include <vector>

using namespace std;

bool dp[40][120][120]; // dp[i][j][k] = i번째에서 a비용이 j, b비용이 k인 경우가 존재하는지 여부

int solution(vector<vector<int>> info, int n, int m) {   
    
    memset(dp, false, sizeof(dp));
    
    dp[0][info[0][0]][0] = true;
    dp[0][0][info[0][1]] = true;
    
    for(int i = 1; i < info.size(); ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < m; ++k)
            {
                dp[i][j][k] = 
                    ((j-info[i][0] >= 0) ? dp[i-1][j-info[i][0]][k] : false)
                    || ((k-info[i][1] >= 0) ? dp[i-1][j][k-info[i][1]] : false);
            }
        }
    }
    
    for(int a = 0; a < n; ++a)
    {
        for(int b = 0; b < m; ++b)
        {
            if(dp[info.size()-1][a][b])
            {
                return a;                
            }
        }
    }
    
    return -1;
}