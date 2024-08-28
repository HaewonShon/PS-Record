#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    while(cin>>n)
    {
        if(n == 0) break;

        vector<int> v(n+1);
        for(int i = 1; i <= n; ++i)
        {
            cin>>v[i];
        }

        bool isAmbiguous = true;
        for(int i = 1; i <= n; ++i)
        {
            if(i != v[v[i]])
            {
                isAmbiguous = false;
                break;
            }
        }

        if(isAmbiguous)
        {
            cout<<"ambiguous\n";
        }
        else
        {
            cout<<"not ambiguous\n";
        }
    }
}
