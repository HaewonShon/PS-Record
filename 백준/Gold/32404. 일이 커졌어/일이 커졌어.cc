#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    int val = n;
    
    for(int i = (((n-1) % 2 == 1) ? n-2 : n-1); i >= 0; i -= 2)
    {
        v[i] = val--;
    }
    for(int i = 1; i < n; i += 2)
    {
        v[i] = val--;
    }

    for(int i : v)
    {
        cout<<i<<" ";
    }
}