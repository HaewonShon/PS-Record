#include <bits/stdc++.h>
using namespace std;

struct CarInfo
{
    int price, cost, perKilo;
};

struct SpyInfo
{
    int cost = 0;
    string carName = ""; // = "" for no car
};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int tests;
    cin>>tests;

    while(tests--)
    {
        int n, m;
        cin>>n>>m;

        map<string, SpyInfo> spies;
        unordered_map<string, CarInfo> cars;
        for(int i = 0; i < n; ++i)
        {
            string N;
            int p, q, k;
            cin>>N>>p>>q>>k;
            cars[N] = {p, q, k};
        }

        for(int i = 0; i < m; ++i)
        {
            int t;
            string S;
            char e;
            cin>>t>>S>>e;


            if(e == 'p') // pickup
            {
                string carName;
                cin>>carName;

                if(!(spies[S].cost == -1 || spies[S].carName != "")) // 현재 빌린 차가 없어야 함
                {
                    spies[S].carName = carName;
                }
                else
                {
                    spies[S].cost = -1;
                }
            }
            else if(e == 'r') // return
            {
                int d;
                cin>>d;

                if(spies[S].cost != -1 && spies[S].carName != "") // 현재 빌린 차가 있음
                {
                    spies[S].cost += cars[spies[S].carName].cost + cars[spies[S].carName].perKilo * d;
                    spies[S].carName = "";
                }
                else
                {
                    spies[S].cost = -1;
                }
            }
            else if(e == 'a') // accident
            {
                int rate;
                cin>>rate;

                if(spies[S].cost != -1 && spies[S].carName != "") // 현재 빌린 차가 있음
                {
                    CarInfo& car = cars[spies[S].carName];
                    spies[S].cost += (car.price * rate / 100) + ((car.price * rate) % 100 > 0 ? 1 : 0); // 소숫점 올림
                }
                else
                {
                    spies[S].cost = -1;
                }
            }
        }

        for(auto spy : spies)
        {
            if(spy.second.carName == "" && spy.second.cost != -1)
            {
                cout<<spy.first<<" "<<spy.second.cost<<"\n";
            }
            else
            {
                cout<<spy.first<<" INCONSISTENT\n";
            }
        }
    }
}