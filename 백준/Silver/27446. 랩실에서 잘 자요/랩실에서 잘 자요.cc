#include <bits/stdc++.h>
using namespace std;

bool pages[101];

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    memset(pages, false, sizeof(pages));

    while(m--)
    {
        int page;
        cin>>page;
        pages[page] = true;
    }

    int recentPage = 0;
    int ans = 0;

    // 인쇄할 첫페이지 찾기 
    for(int i = 1; i <= n; ++i)
    {
        if(!pages[i])
        {
            ans = 7;
            recentPage = i;
            break;
        }
    }

    for(int i = recentPage + 1; i <= n; ++i)
    {
        if(!pages[i])
        {
            if(i - recentPage <= 3) // 이어서 프린트하는게 이득
            {
                ans += (i - recentPage) * 2;
            }
            else // 따로 프린트하는게 이득
            {
                ans += 7;
            }
            recentPage = i;
        }
    }
    cout<<ans;
}