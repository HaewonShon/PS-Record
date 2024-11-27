#include <bits/stdc++.h>
using namespace std;

char graph[111][11]; // 10*10 + 10 = 110

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    while(n--)
    {
        int a, b;
        cin>>a>>b;

        memset(graph, ' ', sizeof(graph));
        for(int i = 1; i <= 10; ++i)
        {
            graph[a*i+b][i] = '*';
        }

        int graphMaxVal = 10*a + b;

        cout<<"y = "<<a<<"x + "<<b<<"\n";
        for(int y = graphMaxVal; y > 0; --y)
        {
            cout<<"*";
            for(int x = 1; x <= 10; ++x)
            {
                cout<<graph[y][x];
            }
            cout<<"\n";
        }
        cout<<"***********\n";
    }

}