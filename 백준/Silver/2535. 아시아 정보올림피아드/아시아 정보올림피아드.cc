#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin>>n;
    vector<pair<int, pair<int, int>>> v(n); // {-score, {country, student}}

    for(int i = 0; i < n; ++i)
    {
        int country, student, score;
        cin>>country>>student>>score;
        v[i] = {-score, {country, student}};
    }

    sort(v.begin(), v.end());

    cout<<v[0].second.first<<" "<<v[0].second.second<<"\n";
    cout<<v[1].second.first<<" "<<v[1].second.second<<"\n";

    if(v[0].second.first == v[1].second.first)
    {
        int thirdPlaceIndex = 2;
        while(v[thirdPlaceIndex].second.first == v[0].second.first)
        {
            ++thirdPlaceIndex;
        }

        cout<<v[thirdPlaceIndex].second.first<<" "<<v[thirdPlaceIndex].second.second;
    }
    else
    {
        cout<<v[2].second.first<<" "<<v[2].second.second;
    }

}