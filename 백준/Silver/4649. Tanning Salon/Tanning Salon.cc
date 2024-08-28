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
        
        string customers;
        cin>>customers;

        vector<bool> isVisited(26, false);
        vector<bool> isCustomer(26, false);
        int currentCustomers = 0;
        int ans = 0;

        for(char c : customers)
        {
            int index = c-'A';
            if(isVisited[index] && isCustomer[index])
            {
                --currentCustomers;
            }
            else if(isVisited[index] && !isCustomer[index])
            {
                // do nothing;
            }
            else if(!isVisited[index] && currentCustomers < n)
            {
                isVisited[index] = true;
                isCustomer[index] = true;
                ++currentCustomers;
            }
            else
            {
                isVisited[index] = true;
                ++ans;
            }
        }

        if(ans == 0)
        {
            cout<<"All customers tanned successfully.\n";
        }
        else
        {
            cout<<ans<<" customer(s) walked away.\n";
        }
    }
}
