#include <bits/stdc++.h>
using namespace std;

int p, q, a, n;

// return : should keep search?
bool Search(vector<int>& list, int multiple, int& ans)
{
    if(multiple > a) return false; // 더 큰 k에 대해 진행할 필요가 없음
    if(list.size() > n) return false; // 더 많은 수에 대해 진행할 필요가 없음

    int numerator = 0;
    for(int i : list)
    {
        numerator += multiple / i;
    }

    if(numerator * q == multiple * p)
    {
        ++ans;
        return true;
    }

    int nextVal = list.back();
    list.push_back(nextVal);
    while(Search(list, multiple * nextVal, ans))
    {
        list.back() = ++nextVal;
    }
    list.pop_back();

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin>>p>>q>>a>>n;

    vector<int> list(1);
    int ans = 0;
    
    for(int i = 1; i <= a; ++i)
    {
        list[0] = i;
        Search(list, i, ans);
    }
    cout<<ans;
}