#include <bits/stdc++.h>
using namespace std;

const int combinations_2[12][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4},
                                {5, 1}, {5, 2}, {5, 3}, {5, 4},
                                {1, 2}, {2, 4}, {4, 3}, {3, 1}};
                                
const int combinations_3[8][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
                                {5, 1, 2}, {5, 1, 3}, {5, 2, 4}, {5, 3, 4}};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    long long n;
    cin>>n;

    long long diceValues[6]; // {a, b, c, d, e, f}
    for(int i = 0; i < 6; ++i) cin>>diceValues[i];

    if(n == 1) // 가장 큰 값이 밑으로
    {
        int total = 0;
        long long maxVal = 0;
        for(int i = 0; i < 6; ++i)
        {
            total += diceValues[i];
            maxVal = max(maxVal, diceValues[i]);
        }

        cout<<total - maxVal;
        return 0;
    }

    long long minVal[3] = { INT_MAX, INT_MAX, INT_MAX }; // {1-side, 2-side, 3-side}

    for(int i = 0; i < 6; ++i)
    {
        minVal[0] = min(minVal[0], diceValues[i]);
    }

    for(int i = 0; i < 12; ++i)
    {
        minVal[1] = min(minVal[1], diceValues[combinations_2[i][0]] + diceValues[combinations_2[i][1]]);
    }
    
    for(int i = 0; i < 8; ++i)
    {
        minVal[2] = min(minVal[2], 
            diceValues[combinations_3[i][0]] 
            + diceValues[combinations_3[i][1]]
            + diceValues[combinations_3[i][2]]);
    }
    
    long long dice_3sided = 4;
    long long dice_2sided = 8*n - 12;
    long long dice_1sided = 4*(n-1)*(n-2) + (n-2)*(n-2);
    
    cout<<minVal[0] * dice_1sided + minVal[1] * dice_2sided + minVal[2] * dice_3sided;
}