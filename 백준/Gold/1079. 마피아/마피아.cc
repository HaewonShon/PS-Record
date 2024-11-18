#include <bits/stdc++.h>
using namespace std;

void Night(vector<int>& guilty, vector<vector<int>>& R, const int n, const int mafia, int res, int& ans);

void Day(vector<int>& guilty, vector<vector<int>>& R, const int n, const int mafia, int res, int& ans)
{
    int currentTarget = -1;
    int currentTargetGuilty = -1;

    for(int i = 0; i < n; ++i)
    {
        if(guilty[i] > currentTargetGuilty)
        {
            currentTarget = i;
            currentTargetGuilty = guilty[i];
        }
    }

    if(currentTarget == mafia) return;
    if(currentTarget != -1)
    {
        guilty[currentTarget] = -1;
        Night(guilty, R, n, mafia, res + 1, ans);
        guilty[currentTarget] = currentTargetGuilty;
    }
    
}

void Night(vector<int>& guilty, vector<vector<int>>& R, const int n, const int mafia, int res, int& ans)
{
    ans = max(res, ans);

    for(int i = 0; i < n; ++i)
    {
        if(guilty[i] != -1 && i != mafia)
        {
            int deadGuilty = guilty[i];
            guilty[i] = -1;

            for(int j = 0; j < n; ++j)
            {
                if(guilty[j] != -1)
                {
                    guilty[j] += R[i][j];
                } 
            }

            Day(guilty, R, n, mafia, res, ans);

            for(int j = 0; j < n; ++j)
            {
                if(guilty[j] != -1)
                {
                    guilty[j] -= R[i][j];
                } 
            }

            guilty[i] = deadGuilty;
        }  
    }


}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> guilty(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>guilty[i];
    }

    vector<vector<int>> R(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin>>R[i][j];
        }
    }

    int mafia;
    cin>>mafia;

    int ans = 0;
    
    if(n % 2)
    {
        Day(guilty, R, n, mafia, 0, ans);
    }
    else
    {
        Night(guilty, R, n, mafia, 1, ans);
    }
    cout<<ans;
}