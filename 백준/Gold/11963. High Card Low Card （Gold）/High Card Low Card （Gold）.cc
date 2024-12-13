#include <bits/stdc++.h>
using namespace std;

bool isCardAppeared[100'001];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    memset(isCardAppeared, false, sizeof(isCardAppeared));

    int n;
    cin>>n;

    vector<int> bessieCards(n);
    int bessieCardsIndex = 0;
    vector<int> elsieCards(n);

    for(int i = 0; i < n; ++i)
    {
        cin>>elsieCards[i];
        isCardAppeared[elsieCards[i]] = true;
    }

    for(int i = 1; i <= 2*n; ++i)
    {
        if(!isCardAppeared[i]) bessieCards[bessieCardsIndex++] = i;
    }

    sort(bessieCards.begin(), bessieCards.end(), [](int v1, int v2) { return v1 > v2; });

    int ans = 0;

    // first n/2
    sort(elsieCards.begin(), elsieCards.begin() + n/2,  [](int v1, int v2) { return v1 > v2; });
    int elsieIndex = 0;
    int bessieIndex = 0;
    while(elsieIndex < n/2 && bessieIndex < n/2)
    {
        if(elsieCards[elsieIndex] > bessieCards[bessieIndex]) ++elsieIndex;
        else
        {
            ++elsieIndex;
            ++bessieIndex;
            ++ans;
        }
    }

    // last n/2
    sort(elsieCards.begin() + n/2, elsieCards.end());
    sort(bessieCards.begin() + n/2, bessieCards.end());
    elsieIndex = n/2;
    bessieIndex = n/2;
    while(elsieIndex < n && bessieIndex < n)
    {
        if(elsieCards[elsieIndex] < bessieCards[bessieIndex]) ++elsieIndex;
        else
        {
            ++elsieIndex;
            ++bessieIndex;
            ++ans;
        }
    }

    cout<<ans;
}