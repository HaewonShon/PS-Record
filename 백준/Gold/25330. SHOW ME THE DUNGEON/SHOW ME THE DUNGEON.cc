#include <bits/stdc++.h>
using namespace std;

int n;
int damage[20];
int people[20];
int visited[1<<20]; // 각 마을 방문 bitmasking으로 표현, 남은 체력

void DFS(int health, int attackPower, int saved, int visit, int& ans)
{
    ans = max(ans, saved);

    if(visit == (1<<n)-1) return;

    for(int i = 0; i < n; ++i)
    {
        int bit = 1 << i;
        if(!(visit & bit))
        {
            int newVisit = visit | bit;
            int newDamage = attackPower + damage[i];
            int newHealth = health - newDamage;
            int newSaved = saved + people[i];
            if(newHealth >= 0 && newHealth > visited[newVisit])
            {
                visited[newVisit] = newHealth;
                DFS(newHealth, newDamage, newSaved, newVisit, ans);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int k;
    cin>>n>>k;

    for(int i = 0; i < n; ++i) cin>>damage[i];
    for(int i = 0; i < n; ++i) cin>>people[i];
    memset(visited, -1, sizeof(visited));

    int ans = 0;
    DFS(k, 0, 0, 0, ans);
    cout<<ans;
}