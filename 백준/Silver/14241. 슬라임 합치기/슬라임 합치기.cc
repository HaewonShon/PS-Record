#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int v;
    cin>>v;

    int score = 0;

    for(int i = 1; i < n; ++i)
    {
        int v2;
        cin>>v2;

        score += v * v2;
        v += v2;    
    }

    cout<<score;
}