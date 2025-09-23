#include <bits/stdc++.h>
using namespace std;

int arr[1000][1000];

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
           cin>>arr[i][j];
        }
    }

    for(int i = 1; i < n-1; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            arr[i][j] *= 2;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j < m-1; ++j)
        {
            arr[i][j] *= 2;
        }
    }

    vector<int> rowSum(n, 0), colSum(m, 0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    int total = accumulate(rowSum.begin(), rowSum.end(), 0);

    if(n > 2)
    {
        int& rowMiddleMinVal = *min_element(rowSum.begin() + 1, rowSum.end() - 1);
        int& rowEndMaxVal = (rowSum[0] > rowSum[n-1]) ? rowSum[0] : rowSum[n-1];

        if(rowMiddleMinVal < 2 * rowEndMaxVal)
        {
            rowEndMaxVal *= 2;
            rowMiddleMinVal /= 2;
        }

        total = max(total, accumulate(rowSum.begin(), rowSum.end(), 0));
    }

    if(m > 2)
    {
        int& colMiddleMinVal = *min_element(colSum.begin() + 1, colSum.end() - 1);
        int& colEndMaxVal = (colSum[0] > colSum[m-1]) ? colSum[0] : colSum[m-1];
        if(colMiddleMinVal < 2 * colEndMaxVal)
        {
            colEndMaxVal *= 2;
            colMiddleMinVal /= 2;
        }

        total = max(total, accumulate(colSum.begin(), colSum.end(), 0));
    }
    cout<<total;

}