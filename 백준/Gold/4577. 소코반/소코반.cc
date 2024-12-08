#include <bits/stdc++.h>
using namespace std;

bool Move(vector<string>& board, int& charX ,int& charY, pair<int, int> dir, int& remainingGoals)
{
    char frontArea = board[charY + dir.second][charX + dir.first];
    
    if(frontArea == '.') // 빈칸->이동
    {
        if(board[charY][charX] == 'W') board[charY][charX] = '+';
        else board[charY][charX] = '.';

        charX += dir.first;
        charY += dir.second;
        board[charY][charX] = 'w';
    }
    else if(frontArea == '+') // 목표점 -> 목표점 위에 있음 표시
    {
        if(board[charY][charX] == 'W') board[charY][charX] = '+';
        else board[charY][charX] = '.';

        charX += dir.first;
        charY += dir.second;
        board[charY][charX] = 'W';
    }
    else if(frontArea == 'b' || frontArea == 'B')
    {
        char front_frontArea = board[charY + dir.second * 2][charX + dir.first * 2];
        if(front_frontArea == '.')
        {
            board[charY + dir.second * 2][charX + dir.first * 2] = 'b';

            if(frontArea == 'B')
            {
                board[charY + dir.second][charX + dir.first] = 'W';
                ++remainingGoals;
            }
            else
            {
                board[charY + dir.second][charX + dir.first] = 'w';
            }
            
            if(board[charY][charX] == 'W') board[charY][charX] = '+';
            else board[charY][charX] = '.';

            charX += dir.first;
            charY += dir.second;
        }
        else if(front_frontArea == '+')
        {
            board[charY + dir.second * 2][charX + dir.first * 2] = 'B';
            --remainingGoals;
            if(frontArea == 'B')
            {
                board[charY + dir.second][charX + dir.first] = 'W';
                ++remainingGoals;
            }
            else
            {
                board[charY + dir.second][charX + dir.first] = 'w';
            }
            
            if(board[charY][charX] == 'W') board[charY][charX] = '+';
            else board[charY][charX] = '.';

            charX += dir.first;
            charY += dir.second;
        }
    }

    if(remainingGoals == 0) return true; // game end
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int gameCount = 1;
    int r, c;
    while(cin>>r>>c)
    {
        if(r == 0 && c == 0) break;

        vector<string> board(r);
        for(int i = 0; i < r; ++i) cin>>board[i];

        int charX, charY;
        int remainingGoals = 0;
        // find character
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(board[i][j] == 'w' || board[i][j] == 'W')
                {   
                    charX = j;
                    charY = i;
                }
                if(board[i][j] == '+' || board[i][j] == 'W')
                {
                    ++remainingGoals;
                }
            }
        }


        string cmd;
        cin>>cmd;

        for(char c : cmd)
        {
            if(c == 'U')
            {
                if(Move(board, charX, charY, {0, -1}, remainingGoals)) break;
            }
            else if(c == 'D')
            {
                if(Move(board, charX, charY, {0, 1}, remainingGoals)) break;
            }
            else if(c == 'L')
            {
                if(Move(board, charX, charY, {-1, 0}, remainingGoals)) break;
            }
            else if(c == 'R')
            {
                if(Move(board, charX, charY, {1, 0}, remainingGoals)) break;
            }
        }

        if(remainingGoals == 0) cout<<"Game "<<gameCount++<<": complete\n";
        else cout<<"Game "<<gameCount++<<": incomplete\n";

        for(int i = 0; i < r; ++i) cout<<board[i]<<"\n";
    }
}