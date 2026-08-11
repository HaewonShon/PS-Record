#include <set>

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        std::set<int> members(nums.begin(), nums.end());
        members.insert(nums[0]);

        int prefixSum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != nums[i-1]+1)
            {
                break;
            }

            prefixSum += nums[i];
        }

        do
        {
            if(members.find(prefixSum) == members.end())
            {
                return prefixSum;
            }
        } while(++prefixSum);
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna