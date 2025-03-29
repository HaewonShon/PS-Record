#include <cstring>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int minDamageForGroup[300001][2]; // {그룹장 참여, 그룹장 참여 x}

int GetMinDamage(const vector<int>& sales, map<int, vector<int>>& teams,
                int teamIndex, bool isLeaderJoined)
{
    if(teams.find(teamIndex) == teams.end()) return 0;
    
    if(isLeaderJoined)
    {
        if(minDamageForGroup[teamIndex][0] != -1) return minDamageForGroup[teamIndex][0];
        
        int res = 0;
        for(int member : teams[teamIndex])
        {
            res += GetMinDamage(sales, teams, member, false);
        }
        
        minDamageForGroup[teamIndex][0] = res;
        return res;
    }    
    else
    {
        if(minDamageForGroup[teamIndex][1] != -1) return minDamageForGroup[teamIndex][1];
        
        // 1. 팀장이 참여하는 경우
        int res = sales[teamIndex-1];
        for(int member : teams[teamIndex])
        {
            res += GetMinDamage(sales, teams, member, false);
        }

        // 2. 팀원이 참여하는 경우
        for(int member : teams[teamIndex])
        {
            int memberJoinRes = sales[member-1] + GetMinDamage(sales, teams, member, true);
            for(int otherMember : teams[teamIndex])
            {
                if(member != otherMember) 
                    memberJoinRes += GetMinDamage(sales, teams, otherMember, false);
            }
            res = min(res, memberJoinRes);
        }

        minDamageForGroup[teamIndex][1] = res;
        return res;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    
    memset(minDamageForGroup, 0xff, sizeof(minDamageForGroup));
    
    map<int, vector<int>> teams;
    for(auto link : links)
    {
        teams[link[0]].push_back(link[1]);
    }
    
    int answer = min(sales[1] + GetMinDamage(sales, teams, 1, true),
                     GetMinDamage(sales, teams, 1, false));
    
    return answer;
}