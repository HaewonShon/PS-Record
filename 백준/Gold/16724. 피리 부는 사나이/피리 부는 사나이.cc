#include <bits/stdc++.h>
using namespace std;

int GetParent(vector<int>& parent, int index)
{
    if(parent[index] == index) return index;
    parent[index] = GetParent(parent, parent[index]);
    return parent[index];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>board[i][j];
        }
    }
    
    // union find
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<int> parents;
    int groupNum = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(visited[i][j] == -1)
            {
                int y = i;
                int x = j;
                while(visited[y][x] == -1)
                {
                    visited[y][x] = groupNum;
                    if(board[y][x] == 'U') --y;
                    else if(board[y][x] == 'D') ++y;
                    else if(board[y][x] == 'L') --x;
                    else if(board[y][x] == 'R') ++x;

                    if(x < 0 || y < 0 || x >= m || y >= n) break;
                }

                parents.push_back(groupNum);
                if(!(x < 0 || y < 0 || x >= m || y >= n)) // 마지막으로 방문한 칸이 유효하면 해당 칸이 부모일 것
                {
                    parents.back() = visited[y][x];
                }
                ++groupNum;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < parents.size(); ++i)
    {
        if(GetParent(parents, i) == i)
        {
            ++ans;
        }
    }

    cout<<ans;
}