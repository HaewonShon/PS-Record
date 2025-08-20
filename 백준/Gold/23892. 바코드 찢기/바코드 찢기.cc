#include <bits/stdc++.h>
using namespace std;

long long GetValue(const string& s, long long repeat)
{
    long long res = 0;
    for(int i = 0; i < s.length() - 1; ++i)
    {
        if(s[i] == '(' && s[i+1] == ')') ++res;
    }
    res *= repeat;

    if(s.front() == ')' && s.back() == '(') res += repeat - 1LL;

    return res;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin>>n>>k;

    string s1, s2;
    long long r1, r2;
    cin>>s1>>r1>>s2>>r2;

    long long initVal = GetValue(s1, r1);
    long long drinkVal = GetValue(s2, r2);

    if(initVal < k)
    {
        cout<<0;
        return 0;
    }

    if(drinkVal >= k)
    {
        cout<<n;
        return 0;
    }

    long long possibleDrinkCount = (initVal - k + 1LL) / (k - drinkVal) + (((initVal - k + 1LL) % (k - drinkVal)) == 0 ? 0 : 1);
    cout<<min(possibleDrinkCount, n);
}