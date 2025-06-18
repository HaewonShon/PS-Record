#include <bits/stdc++.h>
using namespace std;

int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeapYear(int y)
{
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int y1, y2, m1, m2, d1, d2;
    cin>>y1>>m1>>d1>>y2>>m2>>d2;

    // 1000년 차이?
    if(y2 - y1 > 1000
        || ((y2 == 1000 + y1) && (m2 > m1))
        || ((y2 == 1000 + y1) && (m2 == m1) && (d2 >= d1)))
    {
        cout<<"gg";
        return 0;
    }

    int ans = 0;
    
    if(y1 == y2 && m1 == m2)
    {
        ans += d2 - d1;
    }
    else if(y1 == y2)
    {
        // 다음달 1일
        if(m1 == 2 && IsLeapYear(y1))
        {
            ans += (days[m1] + 1) - d1;
        }
        else
        {
            ans += days[m1] - d1;
        }
        
        ++m1;
        ans += 1;
        
        while(m1 < m2)
        {
            if(m1 == 2 && IsLeapYear(y1))
            {
                ans += 29;
            }
            else
            {
                ans += days[m1];
            }
            ++m1;
        }

        ans += d2 - 1;
    }
    else
    {
        // 다음달 1일// 다음달 1일
        if(m1 == 2 && IsLeapYear(y1))
        {
            ans += 29 - d1;
        }
        else
        {
            ans += days[m1] - d1;
        }
        
        ans += 1;
        if(++m1 == 13)
        {
            m1 = 1;
            y1 += 1;
        }
        else // 다음년도 1월 1일
        {
            while(m1 < 13)
            {
                if(m1 == 2 && IsLeapYear(y1))
                {
                    ans += 29;
                }
                else
                {
                    ans += days[m1];
                }
                ++m1;
            }
            m1 = 1;
            y1 += 1;
        }

        // 년도 맞추기
        while(y1 < y2)
        {
            if(IsLeapYear(y1))
            {
                ans += 366;
            }
            else
            {
                ans += 365;
            }
            ++y1;
        }

        // y1 == y2, m 맞추기
        while(m1 < m2)
        {
            if(m1 == 2 && IsLeapYear(y1))
            {
                ans += 29;
            }
            else
            {
                ans += days[m1];
            }
            ++m1;
        }        

        // y1 == y2, m1 == m2
        ans += d2 - 1;
    }

    cout<<"D-"<<ans;
}