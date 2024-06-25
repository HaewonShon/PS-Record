#include <bits/stdc++.h>
using namespace std;

void GetMaxValue(const vector<vector<int>>& v, int& ans)
{
    for(auto v1 : v)
    {
        for(auto v2 : v1)
        {
            ans = max(v2, ans);
        }
    }
}

void MoveBoard_Up(vector<vector<int>> v, int n, int remaining, int& ans);
void MoveBoard_Down(vector<vector<int>> v, int n, int remaining, int& ans);
void MoveBoard_Left(vector<vector<int>> v, int n, int remaining, int& ans);
void MoveBoard_Right(vector<vector<int>> v, int n, int remaining, int& ans);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>v[i][j];
        }
    }

    int ans = 0;
    MoveBoard_Up(v, n, 5, ans);
    MoveBoard_Down(v, n, 5, ans);
    MoveBoard_Left(v, n, 5, ans);
    MoveBoard_Right(v, n, 5, ans);

    cout<<ans;
}


void MoveBoard_Up(vector<vector<int>> v, int n, int remaining, int& ans)
{
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

    if(remaining > 1)
    {
        MoveBoard_Up(v, n, remaining-1, ans);
        MoveBoard_Down(v, n, remaining-1, ans);
        MoveBoard_Left(v, n, remaining-1, ans);
        MoveBoard_Right(v, n, remaining-1, ans);
    }
    else
    {
        GetMaxValue(v, ans);
    }
}

void MoveBoard_Down(vector<vector<int>> v, int n, int remaining, int& ans)
{
    if(remaining == 0)
    {
        GetMaxValue(v, ans);
    }

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

    if(remaining > 1)
    {
        MoveBoard_Up(v, n, remaining-1, ans);
        MoveBoard_Down(v, n, remaining-1, ans);
        MoveBoard_Left(v, n, remaining-1, ans);
        MoveBoard_Right(v, n, remaining-1, ans);
    }
    else
    {
        GetMaxValue(v, ans);
    }
}

void MoveBoard_Left(vector<vector<int>> v, int n, int remaining, int& ans)
{
    if(remaining == 0)
    {
        GetMaxValue(v, ans);
    }

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

    if(remaining > 1)
    {
        MoveBoard_Up(v, n, remaining-1, ans);
        MoveBoard_Down(v, n, remaining-1, ans);
        MoveBoard_Left(v, n, remaining-1, ans);
        MoveBoard_Right(v, n, remaining-1, ans);
    }
    else
    {
        GetMaxValue(v, ans);
    }
}

void MoveBoard_Right(vector<vector<int>> v, int n, int remaining, int& ans)
{
    if(remaining == 0)
    {
        GetMaxValue(v, ans);
    }

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

    if(remaining > 1)
    {
        MoveBoard_Up(v, n, remaining-1, ans);
        MoveBoard_Down(v, n, remaining-1, ans);
        MoveBoard_Left(v, n, remaining-1, ans);
        MoveBoard_Right(v, n, remaining-1, ans);
    }
    else
    {
        GetMaxValue(v, ans);
    }
}
