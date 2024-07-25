#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>v[i][j];
        }
    }

    // 1. 행 i에는 (1...m) + (m * i)
    // 2. 열 j에는 a, a + m, a + 2m, ..., a + km

    for(int i = 0; i < n; ++i)
    {
        int maxElement = *max_element(v[i].begin(), v[i].end());
        int minElement = *min_element(v[i].begin(), v[i].end());
        if(maxElement - minElement != m-1)
        {
            cout<<"0";
            return 0;
        }
    }

    for(int j = 0; j < m; ++j)
    {
        int offset = v[0][j] % m;
        for(int i = 1; i < n; ++i)
        {
            if(v[i][j] % m != offset)
            {
                cout<<"0";
                return 0;
            }
        }
    }
    cout<<"1";
}