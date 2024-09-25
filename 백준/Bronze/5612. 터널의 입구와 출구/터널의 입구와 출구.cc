#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    int cars;
    cin>>cars;

    int ans = cars;

    for(int i = 0; i < n; ++i)
    {
        int added, removed;
        cin>>added>>removed;
        cars += added;
        cars -= removed;

        ans = max(cars, ans);

        if(cars < 0)
        {
            cout<<0;
            return 0;
        }
    }

    cout<<ans;
}