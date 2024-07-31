#include <bits/stdc++.h>
using namespace std;

int bCount = 0, wCount = 0;

void UpdateQueue(list<char>& q, int status)
{
    if(status == 1) // 아랫방향이 뒤쪽 - 뒤에 있는 공은 떨어짐
    {
        while(!q.empty() && q.back() == 'b')
        {
            --bCount;
            q.pop_back();
        }
    }
    else if(status == 3) // 아랫방향이 앞쪽 - 앞에 있는 공은 떨어짐
    {
        while(!q.empty() && q.front() == 'b')
        {
            --bCount;
            q.pop_front();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int status = 0; // 큐의 앞방향이 0 오른쪽 1 위 2 왼쪽 3 아래
    list<char> q; // 공이 떨어지는 상황-앞뒤로 뺄 수 있어야하므로 list 사용

    int query;
    cin>>query;

    while(query--)
    {
        string cmd;
        cin>>cmd;

        if(cmd == "push")
        {
            char c;
            cin>>c;
            q.push_back(c);

            if(c == 'b') ++bCount;
            else ++wCount;
        }
        else if(cmd == "pop")
        {
            if(!q.empty())
            {
                if(q.front() == 'b') --bCount;
                else --wCount;
                q.pop_front();
            }
        }
        else if(cmd == "rotate")
        {
            char c;
            cin>>c;
            if(c == 'l')
            {
                ++status;
                if(status == 4) status = 0;
            }
            else if(c == 'r')
            {
                --status;
                if(status == -1) status = 3;
            }
        }
        else if(cmd == "count")
        {
            char c;
            cin>>c;

            if(c == 'b') cout<<bCount<<"\n";
            else cout<<wCount<<"\n";
        }
        UpdateQueue(q, status);
    }
}