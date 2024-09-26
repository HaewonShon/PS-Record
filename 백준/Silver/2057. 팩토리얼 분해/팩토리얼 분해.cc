#include <bits/stdc++.h>
using namespace std;

bool DFS(const vector<unsigned long long>& factorials, int index, unsigned long long n)
{
    if(n == 0)
    {
        return true;
    }

    if(n < 0)
    {
        return false;
    }

    for(int i = index; i <= 19; ++i)
    {
        if(DFS(factorials, i+1, n - factorials[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    unsigned long long n;
    cin>>n;

    if(n == 0)
    {
        cout<<"NO";
        return 0;
    }

    vector<unsigned long long> factorials(20, 1); // n의 최댓값 10^18보다 작은 최대 팩토리얼값 = 19!
    for(int i = 1; i <= 19; ++i)
    {
        factorials[i] = factorials[i-1] * i;
    }

    if(DFS(factorials, -1, n))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}