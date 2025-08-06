#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    float totalScore = 0.f;
    int totalCredit = 0;

    while(n--)
    {
        string s, score;
        int credit;
        cin>>s>>credit>>score;

        float scoreInFloat = 0.f;

        if(score[0] == 'A') scoreInFloat = 4.f;
        if(score[0] == 'B') scoreInFloat = 3.f;
        if(score[0] == 'C') scoreInFloat = 2.f;
        if(score[0] == 'D') scoreInFloat = 1.f;

        if(score[1] == '+') scoreInFloat += 0.3f;
        if(score[1] == '-') scoreInFloat -= 0.3f;
        
        totalScore += scoreInFloat * credit;
        totalCredit += credit;
    }

    cout<<fixed<<setprecision(2)<<totalScore / totalCredit;
}