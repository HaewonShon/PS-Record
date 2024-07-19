#include <iostream>

using namespace std;

int main()
{
    int w, h;
    cin>>w>>h;
    w *= 100;
    h *= 100;
    cout<<min(w, h)/2;
}