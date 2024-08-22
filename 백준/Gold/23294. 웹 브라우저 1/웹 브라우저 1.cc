#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> back; // back first
stack<pair<int, int>> front;

vector<int> cacheSize;

int currentCache = 0;
int maxCache;

void Backward(int& currentPage)
{
    if(back.empty()) return;

    if(!front.empty() && front.top().first == currentPage)
    {
        ++front.top().second;
    }
    else
    {
        front.push({currentPage, 1});
    }

    currentPage = back.back().first;
    if(--back.back().second == 0) back.pop_back();
}

void Frontward(int& currentPage)
{
    if(front.empty()) return;

    if(!back.empty() && back.back().first == currentPage)
    {
        ++back.back().second;
    }
    else
    {
        back.push_back({currentPage, 1});
    }
    currentPage = front.top().first;
    if(--front.top().second == 0) front.pop();
}

void Access(int& currentPage, int newPage)
{
    // remove all front
    while(!front.empty())
    {
        currentCache -= front.top().second * cacheSize[front.top().first];
        front.pop();
    }

    if(currentPage != -1)
    {
        if(!back.empty() && back.back().first == currentPage)
        {
            ++back.back().second;
        }
        else
        {
            back.push_back({currentPage, 1});
        }
    }

    currentPage = newPage;
    currentCache += cacheSize[newPage];

    while(currentCache > maxCache)
    {
        currentCache -= cacheSize[back.front().first];
        if(--back.front().second == 0)
        {
            back.pop_front();
        }
    }
}

void Compress()
{
    for(auto& p : back)
    {
        if(p.second > 1)
        {
            currentCache -= cacheSize[p.first] * (p.second - 1);
            p.second = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, q;
    cin>>n>>q>>maxCache;

    cacheSize = vector<int>(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin>>cacheSize[i];
    }
    int currentPage = -1;

    while(q--)
    {
        char cmd;
        cin>>cmd;

        if(cmd == 'B') Backward(currentPage);
        else if(cmd == 'F') Frontward(currentPage);
        else if(cmd == 'A')
        {
            int i;
            cin>>i;
            Access(currentPage, i);
        }
        else if(cmd == 'C') Compress();
    }

    cout<<currentPage<<"\n";

    if(back.empty())
    {
        cout<<"-1\n";
    }
    else
    {
        while(!back.empty())
        {
            while(back.back().second--)
            {
                cout<<back.back().first<<" ";
            }
            back.pop_back();
        }
        cout<<"\n";
    }

    if(front.empty())
    {
        cout<<"-1";
    }
    else
    {
        while(!front.empty())
        {
            while(front.top().second--)
            {
                cout<<front.top().first<<" ";
            }
            front.pop();
        }
    }
}
