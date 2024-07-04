#include <bits/stdc++.h>
using namespace std;

void MoveBoard_Up(vector<vector<int>>& v);
void MoveBoard_Down(vector<vector<int>>& v);
void MoveBoard_Left(vector<vector<int>>& v);
void MoveBoard_Right(vector<vector<int>>& v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int test = 1; test <= t; ++test)
    {
        int n;
        string dir;
        cin>>n>>dir;

        vector<vector<int>> board(n, vector<int>(n));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin>>board[i][j];
            }
        }

        if(dir == "up") MoveBoard_Up(board);
        else if(dir == "down") MoveBoard_Down(board);
        else if(dir == "left") MoveBoard_Left(board);
        else if(dir == "right") MoveBoard_Right(board);

        cout<<"Case #"<<test<<":\n";
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}   

void MoveBoard_Up(vector<vector<int>>& v)
{
    int n = v.size();
    for(int x = 0; x < n; ++x)
    {
        int front = 0;
        for(int y = 1; y < n; ++y)
        {
            if(front == y) continue;
            if(v[y][x] == 0) continue;

            // 빈칸->앞으로 옮기기
            if(v[front][x] == 0)
            {
                v[front][x] = v[y][x];
                v[y][x] = 0;
            }
            else
            {
                // 합치기
                if(v[front][x] == v[y][x])
                {
                    v[front][x] *= 2;
                    v[y][x] = 0;
                    ++front;
                }
                // 다음칸으로 옮기기
                else
                {
                    ++front;
                    if(front != y)
                    {
                        v[front][x] = v[y][x];
                        v[y][x] = 0;
                    }
                }
            }
        }
    }
}

void MoveBoard_Down(vector<vector<int>>& v)
{
    int n = v.size();
    for(int x = 0; x < n; ++x)
    {
        int front = n-1;
        for(int y = n-2; y >= 0; --y)
        {
            if(front == y) continue;
            if(v[y][x] == 0) continue;

            // 빈칸->앞으로 옮기기
            if(v[front][x] == 0)
            {
                v[front][x] = v[y][x];
                v[y][x] = 0;
            }
            else
            {
                // 합치기
                if(v[front][x] == v[y][x])
                {
                    v[front][x] *= 2;
                    v[y][x] = 0;
                    --front;
                }
                // 다음칸으로 옮기기
                else
                {
                    --front;
                    if(front != y)
                    {
                        v[front][x] = v[y][x];
                        v[y][x] = 0;
                    }
                }
            }
        }
    }
}

void MoveBoard_Left(vector<vector<int>>& v)
{
    int n = v.size();
    for(int y = 0; y < n; ++y)
    {
        int front = 0;
        for(int x = 1; x < n; ++x)
        {
            if(front == x) continue;
            if(v[y][x] == 0) continue;

            // 빈칸->앞으로 옮기기
            if(v[y][front] == 0)
            {
                v[y][front] = v[y][x];
                v[y][x] = 0;
            }
            else
            {
                // 합치기
                if(v[y][front] == v[y][x])
                {
                    v[y][front] *= 2;
                    v[y][x] = 0;
                    ++front;
                }
                // 다음칸으로 옮기기
                else
                {
                    ++front;
                    if(front != x)
                    {
                        v[y][front] = v[y][x];
                        v[y][x] = 0;
                    }
                }
            }
        }
    }
}

void MoveBoard_Right(vector<vector<int>>& v)
{
    int n = v.size();
    for(int y = 0; y < n; ++y)
    {
        int front = n-1;
        for(int x = n-2; x >= 0; --x)
        {
            if(front == x) continue;
            if(v[y][x] == 0) continue;

            // 빈칸->앞으로 옮기기
            if(v[y][front] == 0)
            {
                v[y][front] = v[y][x];
                v[y][x] = 0;
            }
            else
            {
                // 합치기
                if(v[y][front] == v[y][x])
                {
                    v[y][front] *= 2;
                    v[y][x] = 0;
                    --front;
                }
                // 다음칸으로 옮기기
                else
                {
                    --front;
                    if(front != x)
                    {
                        v[y][front] = v[y][x];
                        v[y][x] = 0;
                    }
                }
            }
        }
    }
}