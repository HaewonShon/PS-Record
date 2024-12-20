#include <bits/stdc++.h>
using namespace std;

int xOffset[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int yOffset[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool DFS(vector<vector<int>>& board, int p, int q, int x, int y, vector<string>& history)
{
    board[y][x] = true;
    history.push_back(string(1, 'A' + x) + string(1, '1' + y));

    if(history.size() == p * q) return true;
    

    for(int i = 0; i < 8; ++i)
    {
        int newX = x + xOffset[i];
        int newY = y + yOffset[i];
        if(newX >= 0 && newX < q && newY >= 0 && newY < p)
        {
            if(board[newY][newX]) continue;
            if(DFS(board, p, q, newX, newY, history)) return true;
        }
    }

    board[y][x] = false;
    history.pop_back();

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test = 1; test <= t; ++test)
    {
        int p, q;
        cin>>p>>q;

        vector<vector<int>> board(p, vector<int>(q, false));

        vector<string> history;
        for(int x = 0; x < q && history.empty(); ++x)
        {
            for(int y = 0; y < p; ++y)
            {
                if(DFS(board, p, q, x, y, history))
                {
                    break;
                }   
            }
        }

        cout<<"Scenario #"<<test<<":\n";
        if(history.empty())
        {
            cout<<"impossible";
        }        
        else
        {
            for(string& s : history) cout<<s;
        }

        cout<<"\n\n";
    }
}