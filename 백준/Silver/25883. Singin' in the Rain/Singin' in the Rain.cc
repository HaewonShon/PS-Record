#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int test;
    cin>>test;

    while(test--)
    {
        int t, s;
        cin>>t>>s;

        vector<int> tracks(s);
        for(int i = 0; i < s; ++i) cin>>tracks[i];

        int currTrack = tracks.front();

        long long ans = 0;

        for(int i = 1; i < s; ++i)
        {
            currTrack += 1;
            if(currTrack > t) currTrack = 1;

            int forward = tracks[i] - currTrack;
            if(forward < 0) forward += t;

            int backward = currTrack - tracks[i];
            if(backward < 0) backward += t;

            ans += min(forward, backward);
            currTrack = tracks[i];
        }

        cout<<ans<<"\n";
    }

}