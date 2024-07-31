#include <bits/stdc++.h>
using namespace std;

struct Room
{
    int minLevel, maxLevel;
    int playerNum;
    vector<pair<string, int>> players;
};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int p, m;
    cin>>p>>m;

    vector<Room> rooms;

    for(int i = 0; i < p; ++i)
    {
        int level;
        string name;
        cin>>level>>name;

        bool isPlayerJoined = false;
        // 들어갈 방이 있음
        for(Room& room : rooms)
        {
            if(room.playerNum < m && level >= room.minLevel && level <= room.maxLevel)
            {
                isPlayerJoined = true;
                ++room.playerNum;
                room.players.push_back({name, level});
                break;
            }
        }

        // 방 만들기
        if(!isPlayerJoined)
        {
            rooms.push_back({level-10, level+10, 1});
            rooms.back().players.push_back({name, level});
        }
    }

    for(Room& room : rooms)
    {
        if(room.playerNum == m)
        {
            cout<<"Started!\n";

        }
        else
        {
            cout<<"Waiting!\n";
        }

        sort(room.players.begin(), room.players.end());

        for(auto pair : room.players)
        {
            cout<<pair.second<<" "<<pair.first<<"\n";
        }
    }
}