#include <iostream>

using namespace std;


int main()
{
    int n;
    cin>>n;
    
    long long mul = 1;
    for(int i = 0; i < 5; ++i)
    {
        mul *= (n-i);
    }
    cout<<mul / 120;
}