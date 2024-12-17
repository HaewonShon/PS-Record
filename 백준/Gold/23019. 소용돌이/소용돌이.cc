#include <bits/stdc++.h>

using namespace std;

// board에서 바깥에서부터의 depth에 대한 string을 정방향 또는 역방향으로 만들어 반환환
string BuildString(const vector<string>& board, int n, int depth, bool reversed) 
{
    if(n == 1) return string(1, board[depth][depth]);

    int x = depth, y = depth;
    string res;
    
    for(int i = 0; i < n-1; ++i) res += board[y][x+i];
    for(int i = 0; i < n-1; ++i) res += board[y+i][x+n-1];
    for(int i = n-1; i > 0; --i) res += board[y+n-1][x+i];
    for(int i = n-1; i > 0; --i) res += board[y+i][x];

    if(reversed)
    {
        res += res.front();
        reverse(res.begin(), res.end());
        res.pop_back();
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<string> board(n);
        for(int i = 0; i < n; ++i) cin>>board[i];

        string outerString = BuildString(board, n, 0, false);
        string reversedOuterString = BuildString(board, n, 0, true);

        // 가능한 8가지 바깥 string을 정렬하여 최소/최대 찾기기
        vector<pair<string, int>> v;
        for(int i = 0; i < 4; ++i)
        {
            int reversedStartIndex = (i % 2 == 1) ? (4-i) : i;
            v.push_back({outerString.substr((n-1)*i) + outerString.substr(0, (n-1)*i), i});
            v.push_back({reversedOuterString.substr((n-1)*reversedStartIndex) + reversedOuterString.substr(0, (n-1)*reversedStartIndex), i});
        }

        sort(v.begin(), v.end());

        // 가능한 최소/최대 후보를 저장하는 컨테이너
        vector<pair<string, int>> minString{ v.front() };
        vector<pair<string, int>> maxString{ v.back() };
        for(int i = 1; i < 8; ++i)
        {
            if(v[i].first == minString.front().first) minString.push_back(v[i]);
            else break;
        }
        for(int i = 7; i >= 0; --i)
        {
            if(v[i].first == maxString.front().first) maxString.push_back(v[i]);
            else break;
        }
       
        // 가능한 최소/최대 string에 내부 string 만들어 이어붙이기
        int depth = 1;
        while(depth * 2 + 1 <= n)
        {
            int len = n - depth * 2;

            // min
            int count = minString.size();
            for(int i = 0; i < count; ++i)
            {
                string str = BuildString(board, len, depth, false);
                string reversedStr = BuildString(board, len, depth, true);

                int startIndex = minString[i].second;
                int reversedStartIndex = (startIndex % 2 == 1) ? (4-startIndex) : startIndex;
                
                str = str.substr((len-1) * startIndex) + str.substr(0, (len-1) * startIndex);
                reversedStr = reversedStr.substr((len-1) * reversedStartIndex) + reversedStr.substr(0, (len-1) * reversedStartIndex);

                minString[i].first += min(str, reversedStr);
            }

            sort(minString.begin(), minString.end());
            while(minString.size() > 1 && minString.back().first > minString.front().first) 
            {
                minString.pop_back();
            }

            // max
            count = maxString.size();
            for(int i = 0; i < count; ++i)
            {
                string str = BuildString(board, len, depth, false);
                string reversedStr = BuildString(board, len, depth, true);

                int startIndex = maxString[i].second;
                int reversedStartIndex = (startIndex % 2 == 1) ? (4-startIndex) : startIndex;
                
                str = str.substr((len-1) * startIndex) + str.substr(0, (len-1) * startIndex);
                reversedStr = reversedStr.substr((len-1) * reversedStartIndex) + reversedStr.substr(0, (len-1) * reversedStartIndex);

                maxString[i].first += max(str, reversedStr);
            }

            sort(maxString.rbegin(), maxString.rend());
            while(maxString.size() > 1 && maxString.back().first < maxString.front().first) 
            {
                maxString.pop_back();
            }

            ++depth;
        }

        cout<<maxString.front().first<<" "<<minString.front().first<<"\n";
    }
}