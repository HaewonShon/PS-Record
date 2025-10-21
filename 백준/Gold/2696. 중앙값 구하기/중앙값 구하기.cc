#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int mid;
        cin>>mid;

        priority_queue<int> pq_left;
        priority_queue<int, vector<int>, greater<int>> pq_right;

        vector<int> res;
        res.push_back(mid);
        
        pq_left.push(mid);

        for(int i = 1; i < n; ++i)
        {
            int val;
            cin>>val;

            if(val > pq_left.top())
            {
                pq_right.push(val);
                if(pq_right.size() > pq_left.size() + 1)
                {
                    pq_left.push(pq_right.top());
                    pq_right.pop();
                }
            }
            else
            {
                pq_left.push(val);
                if(pq_left.size() > pq_right.size() + 1)
                {
                    pq_right.push(pq_left.top());
                    pq_left.pop();
                }
            }

            if(i % 2 == 0) // 홀수
            {
                if(pq_left.size() > pq_right.size())
                {
                    res.push_back(pq_left.top());
                }
                else
                {
                    res.push_back(pq_right.top());
                }
            }
        }

        cout<<res.size()<<"\n";
        for(int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" ";
            if((i + 1) % 10 == 0)
            {
                cout<<"\n";
            }
        }
        if(res.size() % 10 != 0)
        {
            cout<<"\n";
        }
    }
}   