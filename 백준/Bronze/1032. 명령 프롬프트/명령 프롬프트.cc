#include <iostream>
using namespace std;

int main()
{
    int n;
    string res;
    cin>>n>>res;

    int len = res.length();
    for(int i = 1; i < n; ++i)
    {
        string s;
        cin>>s;

        for(int j = 0; j < len; ++j)
        {
            if(res[j] != '?')
            {
                if(res[j] != s[j])
                {
                    res[j] = '?';
                }
            }
        }
    }   
    cout<<res;
}