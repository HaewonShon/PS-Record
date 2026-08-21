long long GCD(long long a, long long b)
{
    if(b == 0) return a;
    return GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}

void DFS(vector<int>& coins, int index, long long maxVal, vector<int>& subset, vector<vector<int>>& res)
{
    if(index == coins.size())
    {
        if(!subset.empty()) res.push_back(subset);
        return;
    }

    long long lcm = 1;
    for(int s : subset)
    {
        lcm = LCM(s, lcm);
    }
    if(lcm >= maxVal) return;

    subset.push_back(coins[index]);
    DFS(coins, index + 1, maxVal, subset, res);
    subset.pop_back();
    DFS(coins, index + 1, maxVal, subset, res);
}

long long BinarySearch(long long maxVal, int k, vector<vector<int>>& subsets)
{
    long long low = 1;
    long long high = maxVal;
    long long res = high;
    
    while(low <= high)
    {
        long long mid = (low + high) / 2;
        long long count = 0;
        for(auto& subset : subsets)
        {
            long long lcm = 1;
            for(int s : subset)
            {
                lcm = LCM(s, lcm);
            }

            if(subset.size() % 2)
            {
                count += mid / lcm;
            }
            else
            {
                count -= mid / lcm;
            }
        }
        if(count >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        if(coins[0] == 1) return k;

        vector<int> prunedCoins;
        for(int i = 0; i < coins.size(); ++i)
        {
            bool isValid = true;;
            for(int coin : prunedCoins)
            {
                if(coins[i] % coin == 0)
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid) prunedCoins.push_back(coins[i]);
        }

        vector<vector<int>> subsets;
        vector<int> subset;
        DFS(prunedCoins, 0, coins[0] * (long long)k, subset, subsets);
        
        return BinarySearch(coins[0] * (long long)k, k, subsets);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna