#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, r1, c1, r2, c2;
    cin>>n>>r1>>c1>>r2>>c2;

    int width = 2*n-1;
    int center = n-1;

    for(int i = r1; i <= r2; ++i)
    {
        for(int j = c1; j <= c2; ++j)
        {
            int dist = abs(center - i % width) + abs(center - j % width);
            if(dist < n)
            {
                char c = 'a' + dist % 26;
                cout<<c;
            }
            else
            {
                cout<<'.';
            }
        }
        cout<<"\n";
    }
}
