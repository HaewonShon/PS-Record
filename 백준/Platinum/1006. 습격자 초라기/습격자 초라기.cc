#include <bits/stdc++.h>
using namespace std;

int dp[10001][3]; // [i][0] - 위칸만 채워짐짐
                    // [i][1] - 아래칸만 채워짐
                    // [i][2] - 둘다 채워짐

bool DEBUG = false;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, w;
        cin>>n>>w;

        vector<vector<int>> v(2, vector<int>(n));
        for(int i = 0; i < n; ++i) cin>>v[0][i];
        for(int i = 0; i < n; ++i) cin>>v[1][i];

        if(n == 1)
        {
            cout<<((v[0][0] + v[1][0] <= w) ? 1 : 2)<<"\n";
            continue;
        }
        else if(n == 2)
        {
            // a b
            // c d
            bool ab = v[0][0] + v[0][1] <= w;
            bool cd = v[1][0] + v[1][1] <= w;
            bool ac = v[0][0] + v[1][0] <= w;
            bool bd = v[0][1] + v[1][1] <= w;

            if((ab && cd) || (ac && bd)) cout<<2<<"\n";
            else if(ab || cd || ac || bd) cout<<3<<"\n";
            else cout<<4<<"\n";
            continue;
        }


        int ans = INT_MAX;
        memset(dp, -1, sizeof(dp));
        // case 1: n-1 ~ 0 연결 x
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = (v[0][0] + v[1][0] <= w) ? 1 : 2;

        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = dp[i-1][2] + 1;
            if(v[0][i-1] + v[0][i] <= w) dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
            
            dp[i][1] = dp[i-1][2] + 1;
            if(v[1][i-1] + v[1][i] <= w) dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);

            dp[i][2] = dp[i-1][2] + ((v[0][i] + v[1][i] <= w) ? 1 : 2);
            dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
            if((v[0][i-1] + v[0][i] <= w) && (v[1][i-1] + v[1][i] <= w))
            {
                dp[i][2] = min(dp[i][2], (i >= 2) ? dp[i-2][2] + 2 : 2);
            }
        }
        ans = min(ans, dp[n-1][2]);

        if(DEBUG) cout<<"case 1: "<<ans<<"\n";

        // case 2: n-1 ~ 0 위만 연결
        if(v[0][0] + v[0][n-1] <= w)
        {
            memset(dp, -1, sizeof(dp));

            dp[0][0] = 1;
            dp[0][1] = 1;
            dp[0][2] = 2;

            dp[1][0] = 3;
            dp[1][1] = (v[1][0] + v[1][1] <= w) ? 2 : 3;
            dp[1][2] = (v[1][0] + v[1][1] <= w || v[0][1] + v[1][1] <= w) ? 3 : 4;

            for(int i = 2; i < n; ++i)
            {
                dp[i][0] = dp[i-1][2] + 1;
                if(v[0][i-1] + v[0][i] <= w) dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
                
                dp[i][1] = dp[i-1][2] + 1;
                if(v[1][i-1] + v[1][i] <= w) dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);

                dp[i][2] = dp[i-1][2] + ((v[0][i] + v[1][i] <= w) ? 1 : 2);
                dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
                if(v[0][i-1] + v[0][i] <= w && v[1][i-1] + v[1][i] <= w)
                {
                    dp[i][2] = min(dp[i][2], dp[i-2][2] + 2);
                }
            }

            ans = min(ans, dp[n-1][1]);
            if(DEBUG) cout<<"case 2: "<<ans<<"\n";
        }

        // case 3: n-1 ~ 0 아래만 연결
        if(v[1][0] + v[1][n-1] <= w)
        {
            memset(dp, -1, sizeof(dp));

            dp[0][0] = 1;
            dp[0][1] = 1;
            dp[0][2] = 2;

            dp[1][0] = (v[0][0] + v[0][1] <= w) ? 2 : 3;
            dp[1][1] = 3;
            dp[1][2] = (v[0][0] + v[0][1] <= w || v[0][1] + v[1][1] <= w) ? 3 : 4;

            for(int i = 2; i < n; ++i)
            {
                dp[i][0] = dp[i-1][2] + 1;
                if(v[0][i-1] + v[0][i] <= w) dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
                
                dp[i][1] = dp[i-1][2] + 1;
                if(v[1][i-1] + v[1][i] <= w) dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);

                dp[i][2] = dp[i-1][2] + ((v[0][i] + v[1][i] <= w) ? 1 : 2);
                dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
                if(v[0][i-1] + v[0][i] <= w && v[1][i-1] + v[1][i] <= w)
                {
                    dp[i][2] = min(dp[i][2], dp[i-2][2] + 2);
                }
            }

            ans = min(ans, dp[n-1][0]);
            if(DEBUG) cout<<"case 3: "<<ans<<"\n";
        }
        // case 4: n-1 ~ 0 둘다 연결
        if(v[0][0] + v[0][n-1] <= w && v[1][0] + v[1][n-1] <= w)
        { 
            memset(dp, -1, sizeof(dp));

            dp[0][0] = 1;
            dp[0][1] = 1;
            dp[0][2] = 2;

            dp[1][0] = 3;
            dp[1][1] = 3;
            dp[1][2] = (v[0][1] + v[1][1] <= w) ? 3 : 4;

            for(int i = 2; i < n; ++i)
            {
                dp[i][0] = dp[i-1][2] + 1;
                if(v[0][i-1] + v[0][i] <= w) dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
                
                dp[i][1] = dp[i-1][2] + 1;
                if(v[1][i-1] + v[1][i] <= w) dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);

                dp[i][2] = dp[i-1][2] + ((v[0][i] + v[1][i] <= w) ? 1 : 2);
                dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);
                if(v[0][i-1] + v[0][i] <= w && v[1][i-1] + v[1][i] <= w)
                {
                    dp[i][2] = min(dp[i][2], dp[i-2][2] + 2);
                }
            }

            ans = min(ans, dp[n-2][2]);
            if(DEBUG) cout<<"case 4: "<<ans<<"\n";

        }
        cout<<ans<<"\n";
    }
}