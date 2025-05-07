#include <bits/stdc++.h>
using namespace std;

int memo[1000001][2]; // [i][0] = 다음 R position
                        // [i][1] = 이전 B position

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n, q;
    cin>>n>>q;

    string s;
    cin>>s;

    int nextR = -1;
    for(int i = n-1; i >= 0; --i)
    {
        memo[i][0] = nextR;
        if(s[i] == 'R') nextR = i;
    }

    int prevB = -1;
    for(int i = 0; i < n; ++i)
    {
        memo[i][1] = prevB;
        if(s[i] == 'B') prevB = i;
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int a = (s[l] == 'R') ? l : memo[l][0];
        int d = (s[r] == 'B') ? r : memo[r][1];

        if(a != -1 && d != -1)
        {
            int b = memo[a][0];
            int c = memo[d][1];
            
            if(b != -1 && c != -1 && b < c)
            {
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
                continue;
            }
        }
        cout<<-1<<"\n";
    }
}