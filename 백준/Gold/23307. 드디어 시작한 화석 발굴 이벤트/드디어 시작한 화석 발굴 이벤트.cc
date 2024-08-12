#include <bits/stdc++.h>
using namespace std;

struct Fossil
{
    int x, y, size;
    string dir;
};

Fossil FindFossil(vector<string>& m, int n, int i, int j)
{
    // 1. find length
    int len = 5;
    while(i+len < n && j+len < n)
    {
        if(!(m[i][j+len] == '.' && m[i+len][j] == '.')) ++len;
        else break;
    }

    Fossil fossil;
    fossil.x = j + (len-1)/2;
    fossil.y = i + (len-1)/2;
    fossil.size = len;

    if(m[fossil.y-1][fossil.x] == '#')
    {
        if(m[fossil.y-2][fossil.x+1] == '#') fossil.dir = "UL";
        else fossil.dir = "UR";
    }
    else if(m[fossil.y+1][fossil.x] == '#')
    {
        if(m[fossil.y+2][fossil.x+1] == '#') fossil.dir = "DL";
        else fossil.dir = "DR";
    }
    else if(m[fossil.y][fossil.x-1] == '#')
    {
        if(m[fossil.y-1][fossil.x-2] == '#') fossil.dir = "LD";
        else fossil.dir = "LU";
    }
    else if(m[fossil.y][fossil.x+1] == '#')
    {
        if(m[fossil.y-1][fossil.x+2] == '#') fossil.dir = "RD";
        else fossil.dir = "RU";
    }

    for(int y = i; y < i+len; ++y)
    {
        for(int x = j; x < j+len; ++x)
        {
            m[y][x] = '.';
        }
    }

    return fossil;
}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<string> m(n);
    for(int i = 0; i < n; ++i) cin>>m[i];

    vector<Fossil> ans;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(m[i][j] == '#')
                ans.push_back(FindFossil(m, n, i, j));
        }
    }

    sort(ans.begin(), ans.end(), [](Fossil& f1, Fossil& f2){
        if(f1.y == f2.y) return f1.x < f2.x;
        return f1.y < f2.y;
    });

    cout<<ans.size()<<"\n";
    for(const Fossil& fossil : ans)
    {
        cout<<fossil.y+1<<" "<<fossil.x+1<<" "<<fossil.size<<" "<<fossil.dir<<"\n";
    }
}