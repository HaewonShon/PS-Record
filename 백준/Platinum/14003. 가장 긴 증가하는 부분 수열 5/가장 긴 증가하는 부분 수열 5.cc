#include <bits/stdc++.h>
using namespace std;

int appear[1000000];

int search(vector<int>& sequence, int target)
{
    int l = 0;
    int r = sequence.size() - 1;

    int res = -1;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(sequence[mid] == target) return mid;

        if(sequence[mid] >= target)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

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

    vector<int> sequence;

    sequence.push_back(v[0]);
    appear[0] = 0;

    for(int i = 1; i < n; ++i)
    {
        if(v[i] > sequence.back())
        {
            sequence.push_back(v[i]);
            appear[i] = sequence.size()-1;
        }
        else
        {
            int index = search(sequence, v[i]);
            sequence[index] = v[i];
            appear[i] = index;
        }
    }


    cout<<sequence.size()<<"\n";
    int sequenceIndex = sequence.size() - 1;
    int appearIndex = n-1;
    while(sequenceIndex >= 0)
    {
        if(appear[appearIndex] == sequenceIndex)
        {
            sequence[sequenceIndex] = v[appearIndex];
            --sequenceIndex;
        }
        --appearIndex;
    }
    
    for(int val : sequence)
    {
        cout<<val<<" ";
    }
}