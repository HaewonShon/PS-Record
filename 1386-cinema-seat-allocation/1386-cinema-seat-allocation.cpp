class Solution {
public:
    const int GROUP_LEFT = 1 << 0;
    const int GROUP_RIGHT = 1 << 1;
    const int GROUP_MID = 1 << 2; 

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = n * 2; // 2 groups per row

        // 0 - none, 1 - left half, 2 - right half, 3 - middle, none - left & right
        unordered_map<int, int> seatStatus;

        for(auto& seat : reservedSeats)
        {
            if(seat[1] == 1 || seat[1] == 10) continue;

            auto status = seatStatus.find(seat[0]);
            if(status != seatStatus.end()) // none
            {
                int& val = status->second;
                if(val == 0) continue;

                if((seat[1] >= 2 && seat[1] <= 5) && (val & GROUP_LEFT)) val ^= GROUP_LEFT;
                if((seat[1] >= 6 && seat[1] <= 9) && (val & GROUP_RIGHT)) val ^= GROUP_RIGHT;
                if((seat[1] >= 4 && seat[1] <= 7) && (val & GROUP_MID)) val ^= GROUP_MID;
            }
            else
            {
                int newStatus = 0b0111;
                if(seat[1] >= 2 && seat[1] <= 5) newStatus ^= GROUP_LEFT;
                if(seat[1] >= 6 && seat[1] <= 9) newStatus ^= GROUP_RIGHT;
                if(seat[1] >= 4 && seat[1] <= 7) newStatus ^= GROUP_MID;
                seatStatus[seat[0]] = newStatus;
            }
        
        }

        for(auto p : seatStatus)
        {
            if(p.second == 0) res -= 2;
            else res -= 1;
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna