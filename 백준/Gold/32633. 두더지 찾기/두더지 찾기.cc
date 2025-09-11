#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b, long long L)
{
    long long gcdAB = gcd(a, b);
    long long x = a / gcdAB;
    if(b > L / x) return -1;
    return x * b;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, L;
    cin>>n>>L;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    vector<int> up;
    vector<int> down;

    for(int i = 0; i < n; ++i)
    {
        int b;
        cin>>b;
        
        if(b == 0) down.push_back(a[i]);
        else up.push_back(a[i]);
    }

    sort(down.begin(), down.end());

    if(!down.empty() && down.front() == 1)  // Ai = 1인 i가 있다면 두더지가 항상 있음->실패
    {
        cout<<-1;
        return 0;
    }

    if(!up.empty())
    {
        long long res = up.front();
        for(int i = 1; i < up.size(); ++i)
        {
            res = lcm(res, up[i], L);
            if(res > L || res == -1)
            {
                break;
            }
        }

        if(res > L || res == -1)
        {
            cout<<-1;
            return 0;
        }

        for(int i = 0; i < down.size(); ++i)
        {
            if(res % down[i] == 0)
            {
                cout<<-1;
                return 0;
            }
        }

        cout<<res;
    }
    else
    {
        cout<<1;
    }
}