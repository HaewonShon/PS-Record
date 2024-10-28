#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin>>s;
    int len = s.length();

    int lenStartWithK = 0;
    int lenStartWithS = 0;
    int lenStartWithA = 0;

    for(int i = 0; i < len; ++i)
    {
        switch(s[i])
        {
            case 'K':
            {
                if(lenStartWithK % 3 == 0) ++lenStartWithK;
                if(lenStartWithS % 3 == 1) ++lenStartWithS;
                if(lenStartWithA % 3 == 2) ++lenStartWithA;
            }
            break;
            case 'S':
            {
                if(lenStartWithK % 3 == 1) ++lenStartWithK;
                if(lenStartWithS % 3 == 2) ++lenStartWithS;
                if(lenStartWithA % 3 == 0) ++lenStartWithA;
            }
            break;
            case 'A':
            {
                if(lenStartWithK % 3 == 2) ++lenStartWithK;
                if(lenStartWithS % 3 == 0) ++lenStartWithS;
                if(lenStartWithA % 3 == 1) ++lenStartWithA;
            }
            break;
        }
    }
    // 답 = 제거비용 + 추가비용
    int ansStartWithK = len - lenStartWithK + (len - lenStartWithK);
    int ansStartWithS = len - lenStartWithS + 1 + (len - lenStartWithS - 1);
    int ansStartWithA = len - lenStartWithA + 2 + (len - lenStartWithA - 2);

    int ans = min(ansStartWithK, min(ansStartWithS, ansStartWithA));
    cout<<ans;
}