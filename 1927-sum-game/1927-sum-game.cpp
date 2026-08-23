class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0, rightSum = 0;
        int leftChance = 0, rightChance = 0;

        for(int i = 0; i < num.length() / 2; ++i)
        {
            if(num[i] == '?') ++leftChance;
            else leftSum += num[i] - '0';
        }
        for(int i = num.length() / 2; i < num.length(); ++i)
        {
            if(num[i] == '?') ++rightChance;
            else rightSum += num[i] - '0';
        }

        if((leftChance + rightChance) % 2) // odd -> alice always win
        {
            return true;
        }

        if(leftChance > rightChance)
        {
            if((rightSum - leftSum) == (9 * (leftChance - rightChance) / 2))
            {
                return false;
            }
        }
        else
        {
            if((leftSum - rightSum) == (9 * (rightChance - leftChance) / 2))
            {
                return false;
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna