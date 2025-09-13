    #include <bits/stdc++.h>
    using namespace std;


    int main()
    { 
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n, m, l, k;
        cin>>n>>m>>l>>k;

        std::set<int> boundaryX, boundaryY; // 해당 별을 끝에 포함하는 경계 좌표
        std::vector<pair<int, int>> star(k);
        for(int i = 0; i < k; ++i)
        {
            int x, y;
            cin>>x>>y;

            boundaryX.insert(x); // 별이 왼쪽 경계
            boundaryX.insert(max(x-l, 0)); // 별이 오른쪽 경계
            boundaryY.insert(y);
            boundaryY.insert(max(y-l, 0));

            star[i] = {x, y};
        }

        int ans = 0;
        for(int x : boundaryX)
        {
            for(int y : boundaryY)
            {
                int xRight = min(x + l, n);
                int yBottom = min(y + l, m);
            
                int res = 0;
                for(auto s : star)
                {
                    if(s.first >= x && s.first <= xRight && s.second >= y && s.second <= yBottom)
                    {
                        ++res;
                    }
                }

                ans = max(ans, res);
            }
        }

        cout<<k - ans;
        
    }