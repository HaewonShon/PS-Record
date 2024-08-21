#include <bits/stdc++.h>
using namespace std;

int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s;
    while(cin>>s)
    {
        int year, month, day;
        year = stoi(s.substr(0, s.find('-')));
        s = s.substr(s.find('-') + 1);
        month = stoi(s.substr(0, s.find('-')));
        s = s.substr(s.find('-') + 1);
        day = stoi(s);

        int skippedDays = 10;
        
        for(int y = 1600; y < year; y += 100)
        {
            if(y % 400 == 0) continue;
            ++skippedDays;
        }

        // 해당 년도가 스킵된 윤년
        if(year % 100 == 0 && year % 400 != 0)
        {
            if(month >= 3) ++skippedDays;
        }

        day += (1 + skippedDays);

        while(days[month] < day)
        {
            if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) 
            {
                if (day == 29) // 윤년 2월)
                {
                    break;
                }
                else
                {
                    day -= 29;
                    month = 3;
                }
            }
            else
            {
                day -= days[month];
                month += 1;
                if(month == 13) 
                {
                    month = 1;
                    ++year;
                }
            }
        }

        cout<<year<<"-";
        cout.width(2);
        cout.fill('0');
        cout<<month<<"-";
        cout.width(2);
        cout.fill('0');
        cout<<day<<"\n";
    }
}
