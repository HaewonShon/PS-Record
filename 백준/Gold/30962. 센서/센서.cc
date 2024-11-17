#include <bits/stdc++.h>
using namespace std;

int isSquare[100001]; // i^2 는 i를 저장, 아닐시 0

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> squares;

    memset(isSquare, 0, sizeof(isSquare));
    for(int i = 1; i * i <= 100000; ++i)
    {
        isSquare[i*i] = i;
        squares.push_back(i*i);
    }

    int q;
    cin>>q;

    while(q--)
    {
        float x1, y1, x2, y2, w;
        cin>>x1>>y1>>x2>>y2>>w;

        int ans = 0;

        float sCos1 = x1 * x1 / (x1 * x1 + y1 * y1);
        float sCos2 = x2 * x2 / (x2 * x2 + y2 * y2);

        for(int sX : squares)
        {
            int sY = w - sX;
            if(sY < 1) continue;
            if(isSquare[sY] != 0)
            {
                float x = isSquare[sX];
                float y = isSquare[sY];

                float sCos = x * x / (x * x + y * y);
                if(sCos >= sCos1 && sCos <= sCos2)
                {
                    ++ans;
                }
            }
        }

        cout<<ans<<"\n";
    }
}