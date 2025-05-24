#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    int s;
    cin>>s;

    int indexToSort = 0;
    while(s > 0 && indexToSort < n)
    {
        int indexToBring = indexToSort;
        for(int i = indexToSort + 1; i < n && i - indexToSort <= s; ++i)
        {
            if(v[i] > v[indexToBring]) indexToBring = i;
        }

        for(int i = indexToBring; i > indexToSort; --i)
        {
            swap(v[i], v[i-1]);
        }
        s -= indexToBring - indexToSort;
        ++indexToSort;
    }

    for(int i = 0; i < n; ++i)
    {
        cout<<v[i]<<" ";
    }
}