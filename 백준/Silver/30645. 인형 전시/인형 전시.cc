#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n;
    cin>>r>>c>>n;

    vector<int> doll(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>doll[i];    
    }

    sort(doll.begin(), doll.end());

    vector<int> frontDoll(c);
    
    int ans = 0;
    // set dolls 1st row
    int dollIndex = 0;
    for(; dollIndex < min(n, c); ++dollIndex)
    {
        frontDoll[dollIndex] = doll[dollIndex];
        ++ans;
    }

    for(int row = 1; row < r; ++row)
    {
        for(int col = 0; col < c; ++col)
        {
            while(dollIndex < n)
            {
                int h = doll[dollIndex++];
                if(h > frontDoll[col])
                {
                    frontDoll[col] = h;
                    ++ans;
                    break;
                }
            }
            

            if(dollIndex == n)
            {
                cout<<ans;
                return 0;
            }
        }
    }

    cout<<ans;
}   