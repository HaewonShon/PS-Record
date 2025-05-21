#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 55; // MAX 50자리 * 50개

int GetDecimal(char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    else return 10 + (c - 'A');
}

char Get36Notation(int val)
{
    if(val < 10) return '0' + val;
    else return 'A' + (val - 10);
}

void Add(string& v1, const string& v2) // v1 += v2
{
    bool roundingUp = false;
    string v2WithMaxLen = string(MAX_LEN - v2.length(), '0') + v2;

    for(int i = MAX_LEN - 1; i >= 0; --i)
    {
        int val1 = GetDecimal(v1[i]);
        int val2 = GetDecimal(v2WithMaxLen[i]);

        int sum = val1 + val2 + roundingUp;
        roundingUp = false;

        if(sum >= 36) roundingUp = true;
        v1[i] = Get36Notation(sum % 36);
    }
}

void Add(string& v, int val, int index) // v1 += c << index
{
    bool roundingUp = false; 

    int val1 = GetDecimal(v[index]);
    int val2 = val;

    int sum = val1 + val2;
    
    if(sum >= 36)
    {
        bool roundingUp = true;
        v[index] = Get36Notation(sum % 36);
        --index;

        while(roundingUp && index >= 0)
        {
            sum = GetDecimal(v[index]) + 1;
            roundingUp = false;

            if(sum >= 36) roundingUp = true;

            v[index] = Get36Notation(sum % 36);
            --index;
        }
    }
    else
    {
        v[index] = Get36Notation(sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin>>n;

    vector<string> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }
    cin>>k;

    string total(MAX_LEN, '0');

    vector<string> increaseAmount(36, string(MAX_LEN, '0'));

    // 현재 값의 총합과 각 자릿수를 Z로 바꿨을 때 증가하는 값 기록
    for(int i = 0; i < n; ++i)
    {
        Add(total, v[i]);

        for(int j = 0; j < v[i].length(); ++j)
        {
            Add(increaseAmount[GetDecimal(v[i][j])], GetDecimal('Z') - GetDecimal(v[i][j]), MAX_LEN - (v[i].length() - j));
        }    
    }

    if(total.find_first_not_of('0') == string::npos) // input이 모두 0
    {
        cout<<0;
        return 0;
    }

    // 수를 Z로 바꿨을 때 증가량이 큰 순으로 정렬
    sort(increaseAmount.rbegin(), increaseAmount.rend());

    // 정렬된 상위 k개 합산
    for(int i = 0; i < k; ++i)
    {
        Add(total, increaseAmount[i]);
    }

    // 앞 0 절삭
    total = total.substr(total.find_first_not_of('0'));

    cout<<total;
}