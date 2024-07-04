#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    queue<pair<int, int>> hideQueue;
    queue<pair<pair<int, int>, int>> searchQueue; //{pos, dist}
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == 'X')
            {
                hideQueue.push({i, j});
                v[i][j] = '1';
                break;
            }
        }
        if(!hideQueue.empty()) break;
    }

    int xOffset[4] = {-1, 1, 0, 0};
    int yOffset[4] = {0, 0, -1, 1};
    // 첫번째 점 방문처리
    while(!hideQueue.empty())
    {
        auto p = hideQueue.front();
        searchQueue.push({p, 0});
        hideQueue.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            auto _p = p;
            _p.first += yOffset[i];
            _p.second += xOffset[i];

            if(_p.first < 0 || _p.first >= n || _p.second < 0 || _p.second >= m) continue;

            if(v[_p.first][_p.second] == 'X')
            {
                v[_p.first][_p.second] = '1';
                hideQueue.push(_p);
            }
        }
    }

    // BFS
    while(!searchQueue.empty())
    {
        auto p = searchQueue.front();
        auto pos = p.first;
        searchQueue.pop();

        for(int i = 0; i < 4; ++i)
        {
            auto _pos = pos;
            _pos.first += yOffset[i];
            _pos.second += xOffset[i];

            if(_pos.first < 0 || _pos.first >= n || _pos.second < 0 || _pos.second >= m) continue;

            if(v[_pos.first][_pos.second] == '.')
            {
                v[_pos.first][_pos.second] = '2';
                searchQueue.push({_pos, p.second + 1});
            }
            else if(v[_pos.first][_pos.second] == 'X')
            {
                cout<<p.second;
                return 0;
            }
        }
    }

}   
