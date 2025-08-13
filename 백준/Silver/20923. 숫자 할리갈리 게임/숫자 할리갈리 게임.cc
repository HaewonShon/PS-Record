#include <bits/stdc++.h>
using namespace std;

deque<int> ground[2];

int RunGame(deque<int>& deck, int turn)
{
    ground[turn].push_back(deck.back());
    deck.pop_back();

    if(deck.empty()) return (turn + 1) % 2;

    if(!ground[0].empty() && !ground[1].empty())
    {
        if(ground[0].back() + ground[1].back() == 5) return 1; // su takes card   
    }

    if(ground[turn].back() == 5) return 0; // do takes card

    return -1;
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    deque<int> deck[2];
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin>>a>>b;
        deck[0].push_back(a);
        deck[1].push_back(b);
    }

    for(int turn = 0; turn < m; ++turn)
    {
        int res = RunGame(deck[turn % 2], turn % 2);
        //cout<<"turn: "<<turn<<", res: "<<res<<"\n";
        if(res != -1)
        {
            if(res == 0) // dodo win
            {
                if(deck[1].empty())
                {
                    cout<<"do";
                    return 0;
                }

                while(!ground[1].empty())
                {
                    deck[0].push_front(ground[1].front());
                    ground[1].pop_front();
                }
                while(!ground[0].empty())
                {
                    deck[0].push_front(ground[0].front());
                    ground[0].pop_front();
                }
            }
            else
            {
                if(deck[0].empty())
                {
                    cout<<"su";
                    return 0;
                }

                while(!ground[0].empty())
                {
                    deck[1].push_front(ground[0].front());
                    ground[0].pop_front();
                }
                while(!ground[1].empty())
                {
                    deck[1].push_front(ground[1].front());
                    ground[1].pop_front();
                }
            }
        }
    }

    if(deck[0].size() == deck[1].size())
    {
        cout<<"dosu";
    }
    else if(deck[0].size() > deck[1].size())
    {
        cout<<"do";
    }
    else
    {
        cout<<"su";
    }

}