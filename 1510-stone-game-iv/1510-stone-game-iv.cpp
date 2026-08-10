bool dp[100001];

class Solution {
public:
    bool winnerSquareGame(int n) {
        memset(dp, false, sizeof(dp));
        dp[0] = false;

        vector<int> squares;
        for(int i = 1; i < 330 /*~100*sqrt(10)*/; ++i)
        {
            squares.push_back(i*i);
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int val : squares)
            {
                if(i - val < 0)
                    break;
                
                if(!dp[i - val])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna