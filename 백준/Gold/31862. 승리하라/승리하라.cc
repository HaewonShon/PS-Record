#include <bits/stdc++.h>
using namespace std;

int PlayMatch(vector<int>& winCount, const vector<pair<int, int>>& unfinished, int matchIndex, int k, int bestWinCount, int bestWinnerCount)
{
    if(matchIndex == unfinished.size())
    {
        if(winCount[k] == bestWinCount && bestWinnerCount == 1)
        {
            return 1;
        }
        else return 0;
    }

    int res = 0;

    auto currentMatch = unfinished[matchIndex];
    ++winCount[currentMatch.first];
    
    if(winCount[currentMatch.first] > bestWinCount)
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, winCount[currentMatch.first], 1);
    }
    else if(winCount[currentMatch.first] == bestWinCount)
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, bestWinCount, bestWinnerCount + 1);
    }
    else
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, bestWinCount, bestWinnerCount);
    }

    --winCount[currentMatch.first];
    
    ++winCount[currentMatch.second];
    if(winCount[currentMatch.second] > bestWinCount)
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, winCount[currentMatch.second], 1);
    }
    else if(winCount[currentMatch.second] == bestWinCount)
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, bestWinCount, bestWinnerCount + 1);
    }
    else
    {
        res += PlayMatch(winCount, unfinished, matchIndex+1, k, bestWinCount, bestWinnerCount);
    }
    --winCount[currentMatch.second];

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> winCount(n+1, 0);
    vector<pair<int, int>> unfinished;

    int bestWinCount = 0, bestWinnerCount = 0;
    
    while(m--)
    {
        int a, b, winner;
        cin>>a>>b>>winner;

        if(winner == 0)
        {
            unfinished.push_back({a, b});
        }
        else if(winner == 1)
        {
            ++winCount[a];

            if(winCount[a] > bestWinCount)
            {
                bestWinnerCount = 1;
                bestWinCount = winCount[a];
            }
            else if(winCount[a] == bestWinCount)
            {
                ++bestWinnerCount;
            }
        }
        else
        {
            ++winCount[b];

            if(winCount[b] > bestWinCount)
            {
                bestWinnerCount = 1;
                bestWinCount = winCount[b];
            }
            else if(winCount[b] == bestWinCount)
            {
                ++bestWinnerCount;
            }
        }

    }

    cout<<PlayMatch(winCount, unfinished, 0, k, bestWinCount, bestWinnerCount);
}