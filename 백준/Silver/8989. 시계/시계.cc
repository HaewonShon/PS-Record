#include <bits/stdc++.h>
using namespace std;

float CalcDegreeBetween(int hour, int minute)
{
    hour %= 12;
    float degree1 = 6.f * minute;
    float degree2 = 30.f * hour + minute / 2.f;

    if(degree1 < degree2)
    {
        swap(degree1, degree2);
    } 

    float between1 = degree1 - degree2;
    float between2 = 360.f - between1;

    return min(abs(between1), abs(between2));
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin>>n;

    while(n--)
    {
        vector<pair<string, string>> v(5);
        for(int i = 0; i < 5; ++i)
        {
            string s;
            cin>>s;

            v[i].first = s.substr(0, 2);
            v[i].second = s.substr(3);
        }

        sort(v.begin(), v.end(), [](pair<string, string>& p1, pair<string, string>& p2 ){
            float res1 = CalcDegreeBetween(stoi(p1.first), stoi(p1.second));
            float res2 = CalcDegreeBetween(stoi(p2.first), stoi(p2.second));

            if(abs(res1 - res2) < 0.1f) // 같은 시간. 가능한 최소 각도 차이가 0.5단위이므로 널널하게 확인
            {
                if(p1.first == p2.first) return p1.second < p2.second;
                return p1.first < p2.first;
            }
            return res1 < res2;
        });

        cout<<v[2].first<<":"<<v[2].second<<"\n";
    }
}
