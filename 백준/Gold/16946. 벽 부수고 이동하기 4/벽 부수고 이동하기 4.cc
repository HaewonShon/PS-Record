#include <bits/stdc++.h>
using namespace std;

const int groupOffset = 10;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<int> groups;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            char c;
            cin>>c;
            v[i][j] = c-'0';
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == 0)
            {
                int groupIndex = groups.size();
                groups.push_back(0);
                int boardValue = groupIndex + groupOffset;

                queue<pair<int, int>> q;
                q.push({i, j});
                v[i][j] = boardValue;

                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    ++groups[groupIndex];

                    if(p.first > 0 && v[p.first-1][p.second] == 0)
                    {
                        v[p.first-1][p.second] = boardValue;
                        q.push({p.first-1, p.second});
                    }
                    if(p.first < n-1 && v[p.first+1][p.second] == 0)
                    {
                        v[p.first+1][p.second] = boardValue;
                        q.push({p.first+1, p.second});
                    }
                    if(p.second > 0 && v[p.first][p.second-1] == 0)
                    {
                        v[p.first][p.second-1] = boardValue;
                        q.push({p.first, p.second-1});
                    }
                    if(p.second < m-1 && v[p.first][p.second+1] == 0)
                    {
                        v[p.first][p.second+1] = boardValue;
                        q.push({p.first, p.second+1});
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == 1)
            {
                int res = 1;
                vector<int> nearGroups;

                if(i > 0 && v[i-1][j] != 1)
                {
                    if(find(nearGroups.begin(), nearGroups.end(), v[i-1][j] - groupOffset) == nearGroups.end())
                    {
                        nearGroups.push_back(v[i-1][j] - groupOffset);
                    }
                }
                if(i < n-1 && v[i+1][j] != 1)
                {
                    if(find(nearGroups.begin(), nearGroups.end(), v[i+1][j] - groupOffset) == nearGroups.end())
                    {
                        nearGroups.push_back(v[i+1][j] - groupOffset);
                    }
                }
                if(j > 0 && v[i][j-1] != 1)
                {
                    if(find(nearGroups.begin(), nearGroups.end(), v[i][j-1] - groupOffset) == nearGroups.end())
                    {
                        nearGroups.push_back(v[i][j-1] - groupOffset);
                    }
                }if(j > 0 && v[i][j-1] != 1)
                {
                    if(find(nearGroups.begin(), nearGroups.end(), v[i][j-1] - groupOffset) == nearGroups.end())
                    {
                        nearGroups.push_back(v[i][j-1] - groupOffset);
                    }
                }
                if(j < m-1 && v[i][j+1] != 1)
                {
                    if(find(nearGroups.begin(), nearGroups.end(), v[i][j+1] - groupOffset) == nearGroups.end())
                    {
                        nearGroups.push_back(v[i][j+1] - groupOffset);
                    }
                }

                for(int group : nearGroups)
                {
                    res += groups[group];
                }
                cout<<res % 10;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<"\n";
    }
}