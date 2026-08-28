void CompletePermu(string& s, bool hasMid, char mid)
{
    int index = s.length() - 1;
    if(hasMid) s += mid;

    while(index >= 0)
    {
        s.push_back(s[index--]);
    }
}

bool BuildPermu(int n, const string& target, string& curr, vector<int>& chars, bool allowEqual = false)
{
    if(curr.length() == (n / 2))
    {
        return allowEqual;
    }

    int index = curr.length();
    if(chars[target[index] - 'a'] >= 2)
    {
        curr += target[index];
        chars[target[index] - 'a'] -= 2;
        if(BuildPermu(n, target, curr, chars, allowEqual))
            return true;
        chars[target[index] - 'a'] += 2;
        curr.pop_back();        
    }

    for(int i = 1 + (target[index] - 'a'); i < 26; ++i)
    {
        if(chars[i] >= 2)
        {
            chars[i] -= 2;
            curr += ('a' + i);
            
            while(curr.length() < n/2)
            {
                for(int i = 0; i < 26; ++i)
                {
                    if(chars[i] >= 2)
                    {
                        chars[i] -= 2;
                        curr += 'a' + i;
                        break;
                    }
                }
            }
            return true;
        }
    }

    return false;
}

vector<int> GetChars(const string& s)
{
    vector<int> chars(26, 0);
    for(char c : s)
    {
        ++chars[c-'a'];
    }
    return chars;
}

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> chars = GetChars(s);

        // is possible?
        int oddChars = 0;
        for(int count : chars)
        {
            if(count % 2 == 1)
            {
                ++oddChars;     
            }
        }

        if(!( ((n % 2) == 0 && oddChars == 0) 
        || ((n % 2) == 1 && oddChars == 1)))
        {
            return "";
        }

        string res;
        if(oddChars == 1)
        {
            char mid;
            for(int i = 0; i < 26; ++i)
            {
                if(chars[i] % 2)
                {
                    mid = 'a' + i;
                    break;
                }
            }

            if(BuildPermu(n, target, res, chars, true))
            {
                CompletePermu(res, true, mid);
                if(res <= target)
                {
                    res = "";
                    chars = GetChars(s);
                    if(BuildPermu(n, target, res, chars))
                    {
                        CompletePermu(res, true, mid);
                        if(res > target) 
                            return res;
                    }
                }
                else
                {
                    return res;
                }
            }
        }
        else
        {
            if(BuildPermu(n, target, res, chars, true))
            {
                CompletePermu(res, false, 0);
                if(res <= target)
                {
                    res = "";
                    chars = GetChars(s);
                    if(BuildPermu(n, target, res, chars))
                    {
                        CompletePermu(res, false, 0);
                        if(res > target) 
                            return res;
                    }
                }
                else
                {
                    return res;
                }
            }
        }
        return "";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna