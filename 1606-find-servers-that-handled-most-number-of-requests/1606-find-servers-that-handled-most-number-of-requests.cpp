class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> working;
        
        for(int i = 0; i < k; ++i)
        {
            available.insert(i);
        }

        vector<int> processedRequests(k, 0);

        int n = arrival.size();
        for(int i = 0; i < n; ++i)
        {
            int time = arrival[i];
            while(!working.empty())
            {
                auto p = working.top();
                if(p.first <= time)
                {
                    working.pop();
                    available.insert(p.second);
                    continue;
                }
                break;
            }

            if(available.empty())
            {
                continue;
            }

            auto res = available.lower_bound(i % k);

            if(res == available.end())
            {
                res = available.begin();
            }

            int server = *res;
            ++processedRequests[server];
            //cout<<"server "<<server<<"processing..\n";
            available.erase(res);
            working.push({time + load[i], server});
        }

        int busiest = -1;
        vector<int> res;
        for(int i = 0; i < k; ++i)
        {
            if(processedRequests[i] > busiest)
            {
                res.clear();
                res.push_back(i);
                busiest = processedRequests[i];
            }
            else if(processedRequests[i] == busiest)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna