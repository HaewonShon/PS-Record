#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<int> givenAns(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin>>givenAns[i];
    }

    vector<bool> isCorrect(n + 1, false);
    for(int i = 0; i < m; ++i)
    {
        int q;
        cin>>q;
        isCorrect[q] = true;
    }

    vector<int> ans(n+1, -1);
    for(int i = 1; i <= n; ++i)
    {
        if(isCorrect[i] == true)
        {
            ans[i] = givenAns[i];
        }
        else
        {
            ans[i] = 1;

            while(ans[i] == ans[i-1] // 이전 답과 같음
            || ans[i] == givenAns[i] // 정답임
            || (i < n && isCorrect[i+1] && ans[i] == givenAns[i+1])) // 다음 정답과 같음
            {
                ++ans[i];
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<" ";
    }
}   