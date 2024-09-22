#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    float x[3];
    float y[3];
    for(int i = 0; i < 3; ++i)
    {
        cin>>x[i]>>y[i];
    }

    float area = abs(x[0]*(y[1]-y[2]) + x[1]*(y[2]-y[0]) + x[2]*(y[0]-y[1])) / 2.f;
    cout<<fixed;
    cout.precision(1);
    cout<<area<<"\n";
    pair<float, float> v[3];
    v[0].first = x[1]-x[0];
    v[0].second = y[1]-y[0];
    v[1].first = x[2]-x[1];
    v[1].second = y[2]-y[1];
    v[2].first = x[0]-x[2];
    v[2].second = y[0]-y[2];

    int n;
    cin>>n;

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        float px, py;
        cin>>px>>py;

        float res[3];

        for(int j = 0; j < 3; ++j)
        {
            pair<float, float> toPoint = {px-x[j], py-y[j]};

            res[j] = v[j].first*toPoint.second - v[j].second*toPoint.first;
        }

        if((res[0] <= 0.f && res[1] <= 0.f && res[2] <= 0.f)
            || (res[0] >= 0.f && res[1] >= 0.f && res[2] >= 0.f))
        {
            ++ans;
        }
    }

    cout<<ans;
}