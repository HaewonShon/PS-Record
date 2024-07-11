#include <bits/stdc++.h>
using namespace std;

int Color(vector<vector<int>>& zone, int a, int b, int c)
{
    if(a == b || b == c) return INT_MAX;

    int res = 54 - (zone[0][a] + zone[1][b] + zone[2][c]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<string> flag(6);
    for(int i = 0; i < 6; ++i)
    {
        cin>>flag[i];
    }

    int ans = INT_MAX;
    // 가로
    {
        vector<vector<int>> zone(3, vector<int>(26, 0));

        for(int i = 0; i < 9; ++i)
        {
            ++zone[0][flag[0][i] - 'A'];
            ++zone[0][flag[1][i] - 'A'];
            ++zone[1][flag[2][i] - 'A'];
            ++zone[1][flag[3][i] - 'A'];
            ++zone[2][flag[4][i] - 'A'];
            ++zone[2][flag[5][i] - 'A'];
        }
        
        priority_queue<pair<int, int>> q[3];
        for(int i = 0; i < 26; ++i)
        {
            q[0].push({zone[0][i], i});
            q[1].push({zone[1][i], i});
            q[2].push({zone[2][i], i});
        }

        int colors[3][3];
        for(int i = 0; i < 3; ++i)
        {
            colors[0][i] = q[0].top().second;
            colors[1][i] = q[1].top().second;
            colors[2][i] = q[2].top().second;
            q[0].pop();
            q[1].pop();
            q[2].pop();
        }

        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3; ++k)
                    ans = min(ans, Color(zone, colors[0][i], colors[1][j], colors[2][k]));
    }
    
    // 세로
    {
        vector<vector<int>> zone(3, vector<int>(26, 0));

        for(int i = 0; i < 6; ++i)
        {
            ++zone[0][flag[i][0] - 'A'];
            ++zone[0][flag[i][1] - 'A'];
            ++zone[0][flag[i][2] - 'A'];
            ++zone[1][flag[i][3] - 'A'];
            ++zone[1][flag[i][4] - 'A'];
            ++zone[1][flag[i][5] - 'A'];
            ++zone[2][flag[i][6] - 'A'];
            ++zone[2][flag[i][7] - 'A'];
            ++zone[2][flag[i][8] - 'A'];
        }

        priority_queue<pair<int, int>> q[3];
        for(int i = 0; i < 26; ++i)
        {
            q[0].push({zone[0][i], i});
            q[1].push({zone[1][i], i});
            q[2].push({zone[2][i], i});
        }

        int colors[3][3];
        for(int i = 0; i < 3; ++i)
        {
            colors[0][i] = q[0].top().second;
            colors[1][i] = q[1].top().second;
            colors[2][i] = q[2].top().second;
            q[0].pop();
            q[1].pop();
            q[2].pop();
        }

        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3; ++k)
                    ans = min(ans, Color(zone, colors[0][i], colors[1][j], colors[2][k]));
    }

    cout<<ans;
}