class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> graph;
        for(auto p : invocations)
        {
            graph[p[0]].push_back(p[1]);
        }

        vector<bool> isSus(n, false);
        
        queue<int> q;
        q.push(k);
        isSus[k] = true;

        while(!q.empty())
        {
            int method = q.front();
            q.pop();

            for(int neighbor : graph[method])
            {
                if(!isSus[neighbor])
                {
                    isSus[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        vector<int> remainings;
        for(int method = 0; method < n; ++method)
        {
            if(isSus[method]) continue;
            
            remainings.push_back(method);
            for(int neighbor : graph[method])
            {
                if(isSus[neighbor])// a group is connected with non-sus
                {
                    std::vector<int> vec(n);
                    std::iota(vec.begin(), vec.end(), 0);
                    return vec;
                }
            }
        }
        return remainings;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna