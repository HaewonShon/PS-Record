class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> frequency(26, 0);

        int maxLength = 0;

        int head = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            ++frequency[c - 'a'];
            while(frequency[c - 'a'] > 2)
            {
                --frequency[s[head] - 'a'];
                ++head;
            }
            maxLength = max(maxLength, i - head + 1);
        }

        return maxLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna