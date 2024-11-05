
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    int y = 0;
    int m = 0;

    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;
        val += 1;

        y += (val / 30) + (val % 30 ? 1 : 0);
        m += (val / 60) + (val % 60 ? 1 : 0);
    }

    y *= 10;
    m *= 15;

    if(y == m)
    {
        cout<<"Y M "<<y;
    }
    else if(y < m)
    {
        cout<<"Y "<<y;
    }
    else
    {
        cout<<"M "<<m;
    }
}