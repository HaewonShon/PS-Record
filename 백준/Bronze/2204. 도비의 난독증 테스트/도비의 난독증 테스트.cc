#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;

    while(cin>>n)
    {
        if(n == 0) break;

        vector<string> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin>>v[i];
        } 

        sort(v.begin(), v.end(), [](string& s1, string& s2){
            string lowerS1 = s1;
            string lowerS2 = s2;
            for(char& c : lowerS1)
            {
                if(c >= 'A' && c <= 'Z') c = tolower(c);
            }
            for(char& c : lowerS2)
            {
                if(c >= 'A' && c <= 'Z') c = tolower(c);
            }
            return lowerS1 < lowerS2;
        });

        cout<<v[0]<<"\n";
    }


}