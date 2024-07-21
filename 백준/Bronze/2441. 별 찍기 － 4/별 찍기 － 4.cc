#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    
    for(int i = 0; i < n; ++i)
    {
        int j = 0;
        for(; j < i; ++j)
        {
            cout<<" ";
        }
        for(; j < n; ++j)
        {
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}