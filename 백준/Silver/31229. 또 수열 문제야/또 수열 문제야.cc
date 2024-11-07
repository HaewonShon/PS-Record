#include <bits/stdc++.h>
using namespace std;

bool isPrime[50000]; // 5000번째 소수 = 48611

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    memset(isPrime, true, sizeof(isPrime));

    vector<int> ans;
    ans.push_back(1);
    int ansCount = 1;

    for(int i = 2; i < 50000; ++i)
    {
        if(isPrime[i])
        {
            ++ansCount;
            ans.push_back(i);

            int j = i + i;
            while(j < 50000)
            {
                isPrime[j] = false;
                j += i;
            }
        }
        
        if(ansCount == n) break;
    }

    for(int val : ans)
    {
        cout<<val<<" ";
    }
}