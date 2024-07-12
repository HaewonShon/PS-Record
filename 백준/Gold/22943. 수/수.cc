#include <bits/stdc++.h>
using namespace std;

bool isPrime[100001];

void CalcPrimes(int val)
{
    isPrime[1] = false;
    int max = (int)sqrt(val);
    for(int i = 2; i <= max; ++i)
    {
        if(isPrime[i] == false) continue;

        int j = 2;
        while(i * j <= val)
        {
            isPrime[i * j] = false;
            ++j;
        } 
    }
}

bool IsAns(int val, const int m)
{
    // 1번 조건: 두 소수의 합
    int i = 2;
    for(; i <= val / 2; ++i)
    {
        if(isPrime[i] == true && isPrime[val - i] == true)
        {
            if(i == val - i) return false;
            break;
        }
    }
    if(i >= val / 2) return false;

    // 2번 조건: m으로 나눠지지 않을 떄까지 나눈 나머지가 두 소수의 곱
    while(val % m == 0) val /= m;

    int sqrtVal = (int)sqrt(val);
    i = 2;
    for(; i <= sqrtVal; ++i)
    {
        if(isPrime[i] == true && val % i == 0 && isPrime[val / i] == true)
        {
            break;
        }
    }
    
    if(i > sqrtVal) return false;
    else return true;
}

int DFS(vector<bool> visit, int k, int depth, int val, const int m)
{
    if(depth == k)
    {
        if(IsAns(val, m)) return 1;
        else return 0;
    }

    int res = 0;
    for(int i = 0; i <= 9; ++i)
    {
        if(visit[i] == true) continue;
        visit[i] = true;
        res += DFS(visit, k, depth + 1, val * 10 + i, m);
        visit[i] = false;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));

    int k, m;
    cin>>k>>m;


    CalcPrimes(std::pow(10, k));

    vector<bool> visit(10, 0);

    int ans = 0;
    for(int i = 1; i <= 9; ++i)
    {
        visit[i] = true;
        ans += DFS(visit, k, 1, i, m);
        visit[i] = false;
    }
    cout<<ans;
}