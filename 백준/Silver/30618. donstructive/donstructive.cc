#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    deque<int> deq;
    while(n > 0)
    {
        if(n % 2 == 0)
        {
            deq.push_front(n--);
        }
        else
        {
            deq.push_back(n--);
        }
    }

    while(!deq.empty())
    {
        cout<<deq.front()<<" ";
        deq.pop_front();
    }
}