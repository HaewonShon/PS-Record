#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int mCount = 0;
    string maxRes, minRes;

    // max
    {
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == 'K')
            {
                maxRes += '5';
                maxRes += string(mCount, '0');
                mCount = 0;
            }
            else
            {
                ++mCount;
            } 
        }

        maxRes += string(mCount, '1');
    }

    // min
    {
        mCount = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == 'K')
            {
                if(mCount > 0)
                {
                    minRes += '1';
                    --mCount;
                    minRes += string(mCount, '0');
                    mCount = 0;
                }

                minRes += '5';
            }
            else
            {
                ++mCount;
            } 
        }
        
        if(mCount > 0)
        {
            minRes += '1';
            --mCount;
            minRes += string(mCount, '0');
        }
    }

    cout<<maxRes<<"\n"<<minRes;
}