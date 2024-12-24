#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    list<int> people;
    for(int i = 1; i <= n; ++i) people.push_back(i);

    cout<<"<";
    for(int i = 0; i < n-1; ++i)
    {
        int _k = (k % people.size() == 0) ? k : (k % people.size());
        for(int j = 0; j < _k - 1; ++j)
        {
            people.push_back(people.front());
            people.pop_front();
        }

        cout<<people.front()<<", ";
        people.pop_front();
    }
    cout<<people.front()<<">";
}