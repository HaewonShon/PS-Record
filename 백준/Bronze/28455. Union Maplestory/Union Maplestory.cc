#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> levels(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>levels[i];
    }

    sort(levels.rbegin(), levels.rend());

    int levelTotal = 0, statTotal = 0;

    for(int i = 0; i < min(n, 42); ++i)
    {
        levelTotal += levels[i];

        if(levels[i] < 60) {}
        else if(levels[i] < 100) { statTotal += 1; }
        else if(levels[i] < 140) { statTotal += 2; }
        else if(levels[i] < 200) { statTotal += 3; }
        else if(levels[i] < 250) { statTotal += 4; }
        else { statTotal += 5; }
    }
    cout<<levelTotal<<" "<<statTotal;
}