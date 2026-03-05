#include <bits/stdc++.h>
using namespace std;

bool isPrime[5000001];

int main()
{ 
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    int n;
    cin>>n;

    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);

            for(int j=i*2; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    int left = 0;
    int right = primes.size() - 1;

    int candidate = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int target = primes[mid];

        cout<< "? " << target<<endl;
        int res;
        cin>>res;
        if(res == 1)
        {
            left = mid + 1;       
        }
        else
        {     
            candidate = target;
            right = mid - 1;
        }
    }
    cout<< "! " << candidate<<endl;
}   