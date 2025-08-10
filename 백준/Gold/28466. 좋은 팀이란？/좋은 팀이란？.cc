#include <bits/stdc++.h>
using namespace std;

int cheongan[10][10];
int jiji[12][12];
priority_queue<int, vector<int>, std::less<int>> pq[10][12];
//priority_queue<int> pq[10][12];

struct Info
{
    int cheongan, jiji, score;
};

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            cin>>cheongan[i][j];
        }
    }

    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            cin>>jiji[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        int score;
        string saju;
        cin>>score>>saju;
        
        int c = saju[0] - '0'; // cheongan
        int j = saju[1] - 'A'; // saju
        pq[c][j].push(score);
    }

    vector<Info> v;
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                if(pq[i][j].empty()) break;

                v.push_back({i, j, pq[i][j].top()});
                pq[i][j].pop();
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        Info& p1 = v[i];
        for(int j = i + 1; j < v.size(); ++j)
        {
            Info& p2 = v[j];
            for(int k = j + 1; k < v.size(); ++k)
            {
                Info& p3 = v[k];

                int score = 0;
                score += p1.score;
                score += p2.score;
                score += p3.score;

                score += cheongan[p1.cheongan][p2.cheongan];
                score += cheongan[p2.cheongan][p3.cheongan];
                score += cheongan[p1.cheongan][p3.cheongan];
                
                score += jiji[p1.jiji][p2.jiji];
                score += jiji[p2.jiji][p3.jiji];
                score += jiji[p1.jiji][p3.jiji];

                ans = max(ans, score);
            }
        }
    }

    cout<<ans;
}