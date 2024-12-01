#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int r, c;
    
    while(cin>>r>>c)
    {
        if(r == 0 && c == 0) break;

        vector<string> rows(r+1);
        vector<string> columns(r);
        for(int i = 0; i < r; ++i)
        {
            cin>>rows[i]>>columns[i];
        }
        cin>>rows[r];

        int ans = 0;

        for(int squareSize = 1; squareSize <= min(r, c); ++squareSize)
        {
            for(int i = 0; i + squareSize <= r; ++i)
            {
                for(int j = 0; j + squareSize <= c; ++j)
                {
                    bool isSquare = true;
                    for(int k = 0; k < squareSize && isSquare; ++k)
                    {
                        if(rows[i][j+k] != '-' || rows[i+squareSize][j+k] != '-')
                        {
                            isSquare = false;
                        }
                    }
                    for(int k = 0; k < squareSize && isSquare; ++k)
                    {
                        if(columns[i+k][j] != '|' || columns[i+k][j+squareSize] != '|')
                        {
                            isSquare = false;
                        }
                    }
                    
                    if(isSquare) ++ans;
                }
            }
        }

        cout<<ans<<" squares\n";
    }
}