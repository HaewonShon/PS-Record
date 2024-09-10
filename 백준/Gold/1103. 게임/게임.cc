#include <bits/stdc++.h>
using namespace std;

int memo[50][50];

int iOffset[4] = {-1, 1, 0, 0};
int jOffset[4] = {0, 0, -1, 1};
const int VISIT_OFFSET = 10;

int DFS(vector<string>& board, int i, int j)
{
    if(memo[i][j] != -1) return memo[i][j];

    if(board[i][j] == 'H') return 0;
    if(board[i][j] > '9') return INT_MAX; // 순환하는 경우

    int res = 0;
    int moveDist = board[i][j] - '0';
    board[i][j] += VISIT_OFFSET;
    for(int k = 0; k < 4; ++k)
    {
        int _i = i + moveDist * iOffset[k];
        int _j = j + moveDist * jOffset[k];
        
        if(_i >= 0 && _i < board.size() && _j >= 0 && _j < board[0].length())
        {
            res = max(res, DFS(board, _i, _j));
            if(res == INT_MAX)
            {
                memo[i][j] = INT_MAX;
                return res; // 순환하는 경우 발견시 즉시 종료
            }
        }
    }
    board[i][j] -= VISIT_OFFSET;

    res += 1;
    memo[i][j] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    memset(memo, -1, sizeof(memo));

    vector<string> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    int res = DFS(v, 0, 0);
    if(res == INT_MAX) cout<<"-1";
    else cout<<res;
}
