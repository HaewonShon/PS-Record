#include <bits/stdc++.h>
using namespace std;

int CountCase(vector<int>& seq, int seqIndex, vector<int>& candidate, int curr, int target)
{
    if(seqIndex == seq.size())
    {
        if(curr == target) return 1;
        else return 0;
    }

    if(seq[seqIndex] != 0)
    {
        int pairCount = 0;
        for(int j = 1; j < seqIndex; ++j)
        {
            if(seq[j] < seq[seqIndex]) ++pairCount;
        }
        return CountCase(seq, seqIndex + 1, candidate, curr + pairCount, target);        
    }
    else
    {
        int res = 0;
        for(int i = 0; i < candidate.size(); ++i)
        {
            if(candidate[i] != -1)
            {
                seq[seqIndex] = candidate[i];
                candidate[i] = -1;
                
                int pairCount = 0;
                for(int j = 1; j < seqIndex; ++j)
                {
                    if(seq[j] < seq[seqIndex]) ++pairCount;
                }
                res += CountCase(seq, seqIndex + 1, candidate, curr + pairCount, target);
                candidate[i] = seq[seqIndex];
            }
        }
        seq[seqIndex] = 0;
        return res;
    }
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, score;
    cin>>n>>score;

    vector<bool> isExist(n+1, false);
    vector<int> seq(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin>>seq[i];
        if(seq[i] != 0) isExist[seq[i]] = true;
        
    }

    vector<int> candidate;
    for(int i = 1; i <= n; ++i)
    {
        if(!isExist[i]) candidate.push_back(i);
    }

    cout<<CountCase(seq, 1, candidate, 0, score);
}   