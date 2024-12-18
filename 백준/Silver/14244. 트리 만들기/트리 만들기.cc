#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    int node = 1;
    for(int i = 0; i < m; ++i) // 0으로부터 leaf m개 만들기
    {
        cout<<"0 "<<node++<<"\n";
    }
    
    while(node < n)
    {
        cout<<node-1<<" "<<node<<"\n";
        ++node;
    }
}