#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin>>v[i];

    deque<int> cardStack;
    int top = 1;
    int currentCard = 2;

    for(int i = n-2; i >= 0; --i)
    {
        if(v[i] == 1)
        {
            cardStack.push_front(top);
            top = currentCard++;
        }
        else if(v[i] == 2)
        {
            cardStack.push_front(currentCard++);
        }
        else if(v[i] == 3)
        {
            cardStack.push_back(currentCard++);
        }
    }

    cout<<top<<" ";
    for(int card : cardStack)
    {
        cout<<card<<" ";
    }
    
}
