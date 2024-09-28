#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> heights(9);
    for(int i = 0; i < 9; ++i)
    {
        cin>>heights[i];
    }

    sort(heights.begin(), heights.end());

    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(i == j) continue;

            int sum = 0;
            for(int k = 0; k < 9; ++k)
            {
                if(k == i || k == j) continue;
                sum += heights[k];
            }

            if(sum == 100)
            {
                for(int k = 0; k < 9; ++k)
                {
                    if(k == i || k == j) continue;
                    cout<<heights[k]<<"\n";
                }
                return 0;
            }
        }
    }
    
}