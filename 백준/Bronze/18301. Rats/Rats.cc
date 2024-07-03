#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n12;
    cin>>n1>>n2>>n12;

    cout<<(int)floor((n1 + 1) * (n2 + 1) / (n12 + 1)) - 1;
}   