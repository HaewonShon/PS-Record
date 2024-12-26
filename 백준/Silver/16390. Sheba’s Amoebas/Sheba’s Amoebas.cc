#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int m, n;
    cin>>n>>m;

    vector<string> dish(n);
    for(int i = 0; i < n; ++i) cin>>dish[i];

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(dish[i][j] == '#')
            {
                ++ans;

                queue<pair<int, int>> q;
                dish[i][j] = '.';
                q.push({i, j});

                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();

                    for(int y = -1; y <= 1; ++y)
                    {
                        for(int x = -1; x <= 1; ++x)
                        {
                            int _i = p.first + y;
                            int _j = p.second + x;
                            if(_i >= 0 && _i < n && _j >= 0 && _j < m)
                            {
                                if(dish[_i][_j] == '#')
                                {
                                    dish[_i][_j] = '.';
                                    q.push({_i, _j});
                                }
                            }                                
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
}