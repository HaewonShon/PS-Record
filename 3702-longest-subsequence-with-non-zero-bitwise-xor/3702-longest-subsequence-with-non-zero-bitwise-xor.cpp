class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorRes = 0;
        int orRes = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            xorRes ^= nums[i];
            orRes |= nums[i];
        }

        if(orRes == 0) return 0;
        if(xorRes == 0)
        {
            for(int i = 0; i < nums.size()/2; ++i)
            {
                int l = i;
                int r = nums.size() - 1 - i;

                if(l != 0 || r != 0)
                {
                    return nums.size() - i - 1;
                }
            }
            return 0;
        }
        else
            return nums.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna