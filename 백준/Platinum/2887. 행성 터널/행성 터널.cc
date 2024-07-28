#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int pos[3], index;
};

int GetParent(vector<int>& parent, int index)
{
    if(index == parent[index]) return index;
    parent[index] = GetParent(parent, parent[index]);
    return parent[index];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<Point> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i].pos[0]>>v[i].pos[1]>>v[i].pos[2];
        v[i].index = i;
    }

    vector<Point> orderedByAxis[3] = {v, v, v};
    for(int i = 0; i < 3; ++i)
    {
        sort(orderedByAxis[i].begin(), orderedByAxis[i].end(), [i](const Point& p1, const Point& p2){
            return p1.pos[i] < p2.pos[i];
        });
    }

    vector<int> parent(n);
    for(int i = 0; i < n; ++i) parent[i] = i;

    parent[0] = 0;
    priority_queue<tuple<int, int, int>> pq; // 다음 가까운 길 {cost, index1, index2}

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            const Point& p1 = orderedByAxis[j][i];
            const Point& p2 = orderedByAxis[j][i-1];

            pq.push({-abs(p1.pos[j] - p2.pos[j]), p1.index, p2.index});
        }
    }

    long long ans = 0;
    while(!pq.empty())
    {
        int cost = -get<0>(pq.top());
        int index1 = get<1>(pq.top());
        int index2 = get<2>(pq.top());
        pq.pop();
        //cout<<"pq: "<<cost<<" "<<index1<<" "<<index2<<"\n";

        if(GetParent(parent, index1) != GetParent(parent, index2))
        {
            parent[GetParent(parent, index2)] = GetParent(parent, index1);
            //cout<<"connect "<<index1<<" "<<index2<<"\n";
            ans += cost;
        }
    }    
    cout<<ans;
}

