#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(m);

    priority_queue<pair<int, pair<bool, int>>> q; // {-value, {isA, index}}

    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i] != 0)
        {
            q.push({-a[i], {true, i}});
        }
    }
    for(int i = 0; i < m; ++i)
    {
        cin>>b[i];
        if(b[i] != 0)
        {
            q.push({-b[i], {false, i}});
        }
    }

    int aIndex = 0;
    int bIndex = 0;

    int currVal = 1;

    while(currVal <= n + m)
    {
        if(!q.empty())
        {
            auto p = q.top();
            if(p.second.first == true) // 다음 val에 A에 있음
            {
                if(currVal == -p.first)
                {
                    ++aIndex;
                    ++currVal;
                    q.pop();
                }
                else
                {
                    if(aIndex < p.second.second) // A 앞부분에 수를 넣을 수 있음
                    {
                        a[aIndex++] = currVal++;
                    }
                    else
                    {
                        b[bIndex++] = currVal++;
                    }
                }
            }
            else
            {
                if(currVal == -p.first)
                {
                    ++bIndex;
                    ++currVal;
                    q.pop();
                }
                else
                {
                    if(bIndex < p.second.second) // A 앞부분에 수를 넣을 수 있음
                    {
                        b[bIndex++] = currVal++;
                    }
                    else
                    {
                        a[aIndex++] = currVal++;
                    }
                }
            }
        }
        else
        {
            if(aIndex == n)
            {
                b[bIndex++] = currVal++;
            }
            else
            {
                a[aIndex++] = currVal++;
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < m; ++i)
    {
        cout<<b[i]<<" ";
    }
}