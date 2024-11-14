#include <bits/stdc++.h>
using namespace std;

bool pages[101];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> cost(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>cost[i];
    }

    vector<int> car(m+1); // 주차 전 - weight, 주차 후 - slot
    for(int i = 1; i <= m; ++i)
    {
        cin>>car[i];
    }

    priority_queue<int, vector<int>, std::greater<int>> availableSlots;
    for(int i = 0; i < n; ++i)
    {
        availableSlots.push(i);
    }

    queue<int> waiting;
    int ans = 0;

    for(int i = 0; i < 2*m; ++i)
    {
        int input;
        cin>>input;

        if(input > 0) // 입차
        {
            if(!availableSlots.empty())
            {
                int slot = availableSlots.top();
                availableSlots.pop();

                ans += cost[slot] * car[input];
                car[input] = slot;
            }
            else
            {
                waiting.push(input);
            }
        }
        else // 출차
        {
            int slot = car[-input];
            if(!waiting.empty())
            {
                int next = waiting.front();
                waiting.pop();
                
                ans += cost[slot] * car[next];
                car[next] = slot;
            }
            else
            {
                availableSlots.push(slot);
            }
        }
    }

    cout<<ans;
}