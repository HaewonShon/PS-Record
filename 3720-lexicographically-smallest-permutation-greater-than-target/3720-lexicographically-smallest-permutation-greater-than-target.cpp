bool BuildPermu(const string& target, vector<int>& chars, string& curr, string& res)
{
    if(target.length() == curr.length())
    {
        return false;
    }

    int index = curr.length();
    if(chars[target[index] - 'a'] > 0)
    {
        curr += target[index];
        --chars[target[index] - 'a'];
        if(BuildPermu(target, chars, curr, res))
        {
            return true;
        }
        ++chars[target[index] - 'a'];
        curr.pop_back();
    }

    int c = (target[index] - 'a') + 1;
    while(c < 26 && chars[c] == 0)
    {
        ++c;
    }

    if(c == 26) return false;
    else
    {
        --chars[c];
        curr += 'a' + c;

        while(curr.length() < target.length())
        {
            for(int i = 0; i < 26; ++i)
            {
                if(chars[i] > 0)
                {
                    --chars[i];
                    curr += 'a' + i;
                    break;
                }
            }
        }

        res = min(res, curr);
        return true;
    }
}

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> chars(26, 0);
        for(char c : s)
        {
            ++chars[c-'a'];
        }

        string res(s.length(), 'z');
        string curr;
        if(!BuildPermu(target, chars, curr, res))
        {
            return "";
        }
        
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna