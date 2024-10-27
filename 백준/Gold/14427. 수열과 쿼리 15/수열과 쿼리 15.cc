#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; // {val, index}

    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
        pq.push({v[i], i+1});
    }
    
    int m;
    cin>>m;

    while(m--)
    {
        int cmd;
        cin>>cmd;

        if(cmd == 1)
        {
            int index, value;
            cin>>index>>value;
            v[index-1] = value;
            pq.push({value, index});
        }
        else
        {
            while(1)
            {
                auto p = pq.top();
                if(p.first == v[p.second-1])
                {
                    cout<<p.second<<"\n";
                    break;
                }
                else
                {
                    pq.pop();
                }
            }
        }
    }
}