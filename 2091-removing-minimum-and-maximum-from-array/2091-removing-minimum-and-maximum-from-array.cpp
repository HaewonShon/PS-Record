class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int index1 = 0, index2 = 0;
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > nums[index1])
                index1 = i;
            if(nums[i] < nums[index2])
                index2 = i;
        }

        if(index1 > index2)
            swap(index1, index2);

        // case 1 : remove both from front
        int res = index2 + 1;

        // case 2 : remove both from back
        res = min(res, n - index1);

        // case 3 : one from front, one from back
        res = min(res, (index1 + 1) + (n - index2));

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna