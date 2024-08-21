#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int H, W;
    cin>>H>>W;

    vector<string> board(H);
    for(int i = 0; i < H; ++i)
    {
        cin>>board[i];
    }

    unsigned long long ans = 0;

    vector<vector<pair<int, int>>> counts(H, vector<pair<int, int>>(W, {0, 0})); // {O count, I count}
    for(int i = H-1; i >= 0; --i)
    {
        for(int j = W-1; j >= 0; --j)
        {
            if(board[i][j] == 'O')
            {
                counts[i][j].first = 1;
            }
            else if(board[i][j] == 'I')
            {
                counts[i][j].second = 1;
            }
            if(j < W-1) counts[i][j].first += counts[i][j+1].first;
            if(i < H-1) counts[i][j].second += counts[i+1][j].second;

            if(board[i][j] == 'J')
            {
                ans += counts[i][j].first * counts[i][j].second;
            }
        }
    }

    cout<<ans;
}
