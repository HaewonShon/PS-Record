#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<vector<int>> board(5, vector<int>(5));
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cin>>board[i][j];
        }
    }

    int r, c;
    cin>>r>>c;

    int ans = 0;
    for(int i = 1; i <= 6; ++i)
    {
        int target = i;

        queue<pair<pair<int, int>, int>> q; // {{r, c}, dist}
        q.push({{r, c}, 0});

        while(!q.empty())
        {
            auto pos = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(board[pos.first][pos.second] == target-100)
            {
                ans += dist;
                r = pos.first;
                c = pos.second;
                break;
            }

            if(pos.first > 0 && board[pos.first-1][pos.second] >= 0)
            {
                board[pos.first-1][pos.second] -= 100;
                q.push({{pos.first-1, pos.second}, dist+1});
            }
            if(pos.first < 4 && board[pos.first+1][pos.second] >= 0)
            {
                board[pos.first+1][pos.second] -= 100;
                q.push({{pos.first+1, pos.second}, dist+1});                
            }
            if(pos.second > 0 && board[pos.first][pos.second-1] >= 0)
            {
                board[pos.first][pos.second-1] -= 100;
                q.push({{pos.first, pos.second-1}, dist+1});                
            }
            if(pos.second < 4 && board[pos.first][pos.second+1] >= 0)
            {
                board[pos.first][pos.second+1] -= 100;
                q.push({{pos.first, pos.second+1}, dist+1});                
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(board[i][j] < -1) board[i][j] += 100;
            }
        }

        if(board[r][c] != target)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
}
