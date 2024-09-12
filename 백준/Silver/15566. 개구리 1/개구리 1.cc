#include <bits/stdc++.h>
using namespace std;

struct Frog
{
    int pos[2];
    int interests[4];
};

bool DFS(const vector<Frog>& frogs, const int n, const vector<vector<pair<int, int>>>& edges,
    vector<int>& current, int index)
{
    if(index > n)
    {
        cout<<"YES\n";
        for(int i = 1; i < current.size(); ++i)
        {
            cout<<current[i]<<" ";
        }
        return true;
    }

    for(int i = 0; i < 2; ++i)
    {
        int pos = frogs[index].pos[i];
        if(current[pos] == -1)
        {
            bool canPlaced = true;

            for(auto p : edges[pos])
            {
                if(current[p.first] != -1)
                {
                    const Frog& neighborFrog = frogs[current[p.first]]; 
                    // 관심도가 다른 개구리가 존재하면 배치할 수 없음
                    if(frogs[index].interests[p.second-1] != neighborFrog.interests[p.second-1])
                    {
                        canPlaced = false;
                        break;
                    }
                }
            }

            if(canPlaced)
            {
                current[pos] = index;
                if(DFS(frogs, n, edges, current, index+1))
                {
                    return true;
                }
                current[pos] = -1;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<Frog> frogs(n+1);

    for(int i = 1; i <= n; ++i)
    {
        cin>>frogs[i].interests[0]
            >>frogs[i].interests[1]
            >>frogs[i].interests[2]
            >>frogs[i].interests[3];
    }

    for(int i = 1; i <= n; ++i)
    {
        cin>>frogs[i].pos[0]
            >>frogs[i].pos[1];
    }

    vector<vector<pair<int, int>>> edges(n+1); // {neighbor, topic}
    for(int i = 0; i < m; ++i)
    {
        int a, b, topic;
        cin>>a>>b>>topic;
        edges[a].push_back({b, topic});
        edges[b].push_back({a, topic});
    }

    vector<int> status(n+1, -1);
    if(!DFS(frogs, n, edges, status, 1))
    {
        cout<<"NO";
    }
}
