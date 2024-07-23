#include <bits/stdc++.h>
using namespace std;

// a를 기준으로 정렬했을때 b가 증가해야한다

int appear[100000]; // i는 sequence의 val에 나타났다
vector<int> sequence; // 가장 긴 부분 수열

int Search(int target)
{
    int l = 0;
    int r = sequence.size()-1;

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

    vector<pair<int, int>> v(n); // {a, b}

    for(int i = 0; i < n; ++i)
    {
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end());

    sequence.push_back(v[0].second);
    appear[0] = 0;

    // 가장 긴 부분 수열 만들기
    for(int i = 1; i < n; ++i)
    {
        if(v[i].second > sequence.back())
        {
            sequence.push_back(v[i].second);
            appear[i] = sequence.size()-1;
        }
        else
        {
            int index = Search(v[i].second);
            sequence[index] = v[i].second;
            appear[i] = index;
        }
    }

    cout<<n - sequence.size()<<"\n";
    int sequenceIndex = sequence.size() - 1;
    int appearIndex = n-1;

    // sequence 업데이트하기 
    while(sequenceIndex >= 0)
    {
        if(appear[appearIndex] == sequenceIndex)
        {
            sequence[sequenceIndex] = v[appearIndex].second;
            --sequenceIndex;
        }
        --appearIndex;
    }

    sequenceIndex = 0;
    // sequnece에 들어가지 않는 수만 출력한다
    for(int i = 0; i < n; ++i)
    {
        if(sequence[sequenceIndex] == v[i].second)
        {
            ++sequenceIndex;
        }
        else
        {
            cout<<v[i].first<<"\n";
        }
    }  
}