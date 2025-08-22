#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> positives;
    vector<int> negatives;
    bool has0 = false;
    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        int val;
        cin>>val;

        if(val > 1) positives.push_back(val);
        else if(val < 0) negatives.push_back(val);
        else if(val == 1) ans += 1;
        else if(val == 0) has0 = true;
    }

    sort(positives.rbegin(), positives.rend());
    sort(negatives.begin(), negatives.end());

    for(int i = 0; i + 1 < positives.size(); i += 2)
    {
        ans += positives[i] * positives[i + 1];
    }
    if(positives.size() % 2 == 1) ans += positives.back();

    for(int i = 0; i + 1 < negatives.size(); i += 2)
    {
        ans += negatives[i] * negatives[i + 1];
    }
    if(negatives.size() % 2 == 1)
    {
        if(!has0) ans += negatives.back();
    } 

    cout<<ans;
}