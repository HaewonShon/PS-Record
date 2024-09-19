#include <bits/stdc++.h>
using namespace std;

void PrintQuadTree(const vector<vector<bool>>& v, int x, int y, int n)
{
    bool isQuadOneColor = true;

    for(int i = 0; i < n && isQuadOneColor; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(v[y][x] != v[y+i][x+j])
            {
                isQuadOneColor = false;
                break;
            }  
        }
    }

    if(!isQuadOneColor)
    {
        cout<<"Q";
        int half = n/2;
        PrintQuadTree(v, x, y, half);
        PrintQuadTree(v, x+half, y, half);
        PrintQuadTree(v, x, y+half, half);
        PrintQuadTree(v, x+half, y+half, half);
    }
    else
    {
        if(v[y][x]) cout<<"B";
        else cout<<"W";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    getline(cin, s); // 1st
    getline(cin, s); // 2nd

    int n = stoi(s.substr(s.find_last_of(' ') + 1));

    vector<vector<bool>> v(n, vector<bool>(n, false));

    getline(cin, s); // 3rd

    int charPerLine = n / 8;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < charPerLine; ++j)
        {
            int val;
            char comma;
            cin>>hex>>val>>comma;

            for(int k = 0; k < 8; ++k)
            {
                v[i][j*8 + k] = val & (1 << k);
            }
        }
    }
    getline(cin, s);
    getline(cin, s); // last line

    cout<<n<<"\n";
    PrintQuadTree(v, 0, 0, n);
}