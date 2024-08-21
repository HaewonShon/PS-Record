#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    unsigned long long A, B;
    cin>>A>>B;
    
    if(A > B)
    {
        swap(A, B);
    }
    unsigned long long size = B - A;
    if(size <= 0)
    {
        cout<<0;
    }
    else
    {
        --size;
        cout<<size<<"\n";
        for(unsigned long long i = A+1; i < B; ++i)
        {
            cout<<i<<" ";
        }
    }
}
