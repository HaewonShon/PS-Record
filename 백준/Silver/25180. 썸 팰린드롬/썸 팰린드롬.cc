#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    // 1자릿수 - 자기 자신
    if(n < 10)
    {
        cout<<1;
        return 0;
    }

    // 9를 최대한 많이 배치
    // 9 두개를 배치->18
    
    int ans = (n / 18) * 2;
    n %= 18;

    if(n > 0)
    {
        // 나머지가 한자릿수라면 해당 수를 가운데 넣는다
        if(n < 10) ++ans;
        // 나머지가 두자릿수라면 짝수->2자리, 홀수->3자리로 해결 가능하다
        else
        {
            if(n % 2) ans += 3;
            else ans += 2;
        }
    }
    cout<<ans;
}