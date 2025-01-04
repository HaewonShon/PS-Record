#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int k, n;
    string s;

    cin>>k>>n;
    cin.ignore();
    getline(cin, s);

    k %= 26;
    k -= 26;
    
    // 오버플로우 방지를 위해 반대방향으로 밀기기
    for(char& c : s)
    {
        if(c >= 'a' && c <= 'z')
        {
            c += k;
            if(c < 'a') c += 26;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c += k;
            if(c < 'A') c += 26;
        }
    }

    cout<<s;
}