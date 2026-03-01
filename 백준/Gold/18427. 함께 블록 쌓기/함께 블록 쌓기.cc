#include <bits/stdc++.h>
using namespace std;

int dp[51][1001]; // i번째 학생까지 해서 j 높이를 만들 수 있는 경우의 수

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));

    int n, m, h;
    cin>>n>>m>>h;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> blocks(n+1);
    for(int i=1; i<=n; i++){
        string s;
        getline(cin, s);

        stringstream ss(s);
        int block = 0;
        blocks[i].push_back(0); // 안쌓는 경우 고려
        while(ss>>block)
        {
            blocks[i].push_back(block);
        }
    }

    dp[0][0] = 1;
    for(int student=1; student<=n; student++){
        for(int height=0; height<=h; height++){
            for(int block : blocks[student]){
                if(height-block >= 0)
                {
                    dp[student][height] += dp[student-1][height-block];
                    dp[student][height] %= 10007;
                }
            }
        }
    }

    cout<<dp[n][h];
}   