#include <bits/stdc++.h>
using namespace std;

auto FindMatchingIt(map<int, int>& db, int key, int k, bool& hasRes)
{
    auto end = db.upper_bound(key + k);
    auto begin = db.lower_bound(key - k);

    vector<map<int, int>::iterator> res;
    
    for(auto it = begin; it != end; ++it)
    {
        res.push_back(it);
    }

    if(abs(end->first - key) <= k) res.push_back(end);

    sort(res.begin(), res.end(), [key](auto p1, auto p2){
        return abs(key - p1->first) < abs(key - p2->first);
    });

    if(res.empty()) hasRes = false;
    else hasRes = true;

    if(res.empty()) return db.end();
    else if(res.size() == 1 || abs(key - res[0]->first) != abs(key - res[1]->first)) return res[0];
    else return db.end();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    map<int, int> db;

    for(int i = 0; i < n; ++i)
    {
        int key, value;
        cin>>key>>value;
        db.insert({key, value});
    }

    for(int i = 0; i < m; ++i)
    {
        int cmd;
        cin>>cmd;

        if(cmd == 1)
        {
            int key, value;
            cin>>key>>value;
            db.insert({key, value});
        }
        else if(cmd == 2)
        {
            int key, value;
            cin>>key>>value;
            
            bool hasRes;
            auto it = FindMatchingIt(db, key, k, hasRes);
            
            if(it != db.end()) it->second = value;
        }
        else if(cmd == 3)
        {
            int key;
            cin>>key;

            bool hasRes;
            auto it = FindMatchingIt(db, key, k, hasRes);
            
            if(it != db.end())
            {
                cout<<it->second<<"\n";
            }
            else
            {
                if(hasRes) cout<<"?\n";
                else cout<<"-1\n";
            }
        }   
    }

}