#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int dp[100001][5][5]; // [왼발, 오른발][위치]

int GetCost(int a, int b)
{
    if(a == b) return 1;
    if(a == 0 || b == 0) return 2;
    if(abs(a-b) == 2) return 4;
    return 3;
}

int Search(const vector<int>& commands, int current, int l, int r, int n)
{
    if(current == n) return dp[current][l][r] = 0;

    if(dp[current][l][r] != -1)
    {
        return dp[current][l][r];
    }

    dp[current][l][r] = MAX;

    return dp[current][l][r] = min(Search(commands, current+1, commands[current], r, n) + GetCost(commands[current], l), 
        Search(commands, current+1, l, commands[current], n) + GetCost(commands[current], r));
}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<int> commands;

    int command;
    while(cin>>command)
    {
        if(command == 0) break;
        commands.push_back(command);
    }

    int n = commands.size();
    commands.erase(unique(commands.begin(), commands.end()), commands.end());
    
    int duplicates = n - commands.size();
    n = commands.size();

    memset(dp, -1, sizeof(dp));

    Search(commands, 0, 0, 0, n);
    cout<<dp[0][0][0] + duplicates;
}