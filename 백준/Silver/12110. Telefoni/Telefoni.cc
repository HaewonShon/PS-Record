#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, d;
    cin>>n>>d;

    int val;
    cin>>val;

    int phone = 0;
    int ans = 0;

    for(int i = 1; i < n; ++i)
    {
        int hasPhone;
        cin>>hasPhone;

        if(hasPhone)
        {
            phone = i;
        }
        else if(i - phone == d)
        {
            phone = i;
            ++ans;
        }
    }

    cout<<ans;
}