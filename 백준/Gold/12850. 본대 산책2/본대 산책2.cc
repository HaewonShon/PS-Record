#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<unsigned long long>> Multiply(const vector<vector<unsigned long long>>& mat1, const vector<vector<unsigned long long>>& mat2)
{
    vector<vector<unsigned long long>> res(8, vector<unsigned long long>(8, 0));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; k++) {
                res[i][j] += mat1[k][i] * mat2[j][k];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector<vector<unsigned long long>> Power(const vector<vector<unsigned long long>>& mat, int power)
{
    vector<vector<unsigned long long>> res(8, vector<unsigned long long>(8, 0));
    for(int i = 0; i < 8; ++i)
    {
        res[i][i] = 1;
    }

    vector<vector<unsigned long long>> multiplier = mat;

    while(power > 0)
    {
        if(power % 2 == 1)
        {
            res = Multiply(res, multiplier);
        }

        multiplier = Multiply(multiplier, multiplier);
        power >>= 1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int d;
    cin>>d;

    vector<vector<unsigned long long>> mat(8);
    mat[0] = vector<unsigned long long>{0, 1, 1, 0, 0, 0, 0, 0};
    mat[1] = vector<unsigned long long>{1, 0, 1, 1, 0, 0, 0, 0};
    mat[2] = vector<unsigned long long>{1, 1, 0, 1, 1, 0, 0, 0};
    mat[3] = vector<unsigned long long>{0, 1, 1, 0, 1, 1, 0, 0};
    mat[4] = vector<unsigned long long>{0, 0, 1, 1, 0, 1, 0, 1};
    mat[5] = vector<unsigned long long>{0, 0, 0, 1, 1, 0, 1, 0};
    mat[6] = vector<unsigned long long>{0, 0, 0, 0, 0, 1, 0, 1};
    mat[7] = vector<unsigned long long>{0, 0, 0, 0, 1, 0, 1, 0};

    vector<vector<unsigned long long>> res = Power(mat, d);

    cout<<res[0][0];
}
