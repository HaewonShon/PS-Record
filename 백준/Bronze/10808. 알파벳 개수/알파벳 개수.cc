#include <iostream>

using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int ans[26] = {0};
    for(char c : s)
    {
        ++ans[c-'a'];
    }
    
    for(int i = 0; i < 26; ++i)
    {
        cout<<ans[i]<<" ";
    }
}