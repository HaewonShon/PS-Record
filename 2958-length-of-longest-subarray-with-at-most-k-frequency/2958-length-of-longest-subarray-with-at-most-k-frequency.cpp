class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, std::list<int>> pos;

        int maxLen = 0;
        int headIndex = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            pos[nums[i]].push_back(i);
            if(pos[nums[i]].size() > k)
            {
                headIndex = max(headIndex, pos[nums[i]].front() + 1);
                pos[nums[i]].pop_front();
            }
            maxLen = max(maxLen, (i - headIndex) + 1);
        }
        return maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna