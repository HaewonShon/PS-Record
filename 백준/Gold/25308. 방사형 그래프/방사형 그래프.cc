#include <bits/stdc++.h>
using namespace std;

const float halfSqrt2 = sqrt(2)/2.f;

float x[8] = {1, halfSqrt2, 0, -halfSqrt2, -1, -halfSqrt2, 0, halfSqrt2};
float y[8] = {0, halfSqrt2, 1, halfSqrt2, 0, -halfSqrt2, -1, -halfSqrt2};

float Cross(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - x2 * y1;
}

bool CheckGraph(vector<int>& permutation)
{
    for(int i = 0; i < 8; ++i)
    {
        int index1 = i;
        int index2 = (i + 1) % 8;
        int index3 = (i + 2) % 8;

        if(Cross(permutation[index3] * x[index3] - permutation[index1] * x[index1], permutation[index3] * y[index3] - permutation[index1] * y[index1],
            permutation[index2] * x[index2] - permutation[index1] * x[index1], permutation[index2] * y[index2] - permutation[index1] * y[index1]) > 0.f)
        {
            return false;
        }
    }    
    return true;
}

void MakePermutation(vector<int>& v, vector<int>& permutation, int n, int& ans)
{
    if(n == 8)
    {
        if(CheckGraph(permutation)) ++ans;
        return;
    }

    for(int i = 0; i < 8; ++i)
    {
        if(v[i] != -1)
        {
            permutation[n] = v[i];
            v[i] = -1;
            MakePermutation(v, permutation, n+1, ans);
            v[i] = permutation[n];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    vector<int> stats(8);
    for(int i = 0; i < 8; ++i)
    {
        cin>>stats[i];
    }

    int ans = 0;
    vector<int> permutation(8, -1);
    MakePermutation(stats, permutation, 0, ans);
    cout<<ans;
}