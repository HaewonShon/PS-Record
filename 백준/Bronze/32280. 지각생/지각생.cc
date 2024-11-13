#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> v(n+1);
    int teacherArrivalTime;
    for(int i = 0; i <= n; ++i)
    {
        string time, type;
        cin>>time>>type;

        v[i].first += (time[0] - '0') * 10 * 60;
        v[i].first += (time[1] - '0') * 60;
        v[i].first += (time[3] - '0') * 10;
        v[i].first += (time[4] - '0');

        if(type == "student")
        {
            v[i].second = 1;
        }
        else
        {
            v[i].second = 0;
            teacherArrivalTime = v[i].first;
        }
    }

    string timeLimit;
    cin>>timeLimit;
    int convertedTimeLimit = 0;
    convertedTimeLimit += (timeLimit[0] - '0') * 10 * 60;
    convertedTimeLimit += (timeLimit[1] - '0') * 60;
    convertedTimeLimit += (timeLimit[3] - '0') * 10;
    convertedTimeLimit += (timeLimit[4] - '0');
    convertedTimeLimit = max(convertedTimeLimit, teacherArrivalTime);

    sort(v.begin(), v.end());

    for(int i = 0; i <= n; ++i)
    {
        if(v[i].first >= convertedTimeLimit)
        {
            if(v[i].second == 0) // 선생
            {
                cout<<n-i;
            }
            else // 학생
            {
                cout<<n-i+1;
            }
            return 0;
        }
    }

    cout<<0;
}