#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<string>& field, int x, int y, int n)
{
    if(x == n-1 && y == n-1) return true;
    if(x >= n || y >= n) return false;
    if(field[y][x] == 'x') return false;

    field[y][x] = 'x';
    return (DFS(field, x+1, y, n) | DFS(field, x, y+1, n));
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> field(n);

    for(int i = 0; i < n; ++i) cin>>field[i];

    if(DFS(field, 0, 0, n))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}