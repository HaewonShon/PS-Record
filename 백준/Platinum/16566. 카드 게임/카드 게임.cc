#include <bits/stdc++.h>
using namespace std;

int FindGroup(const vector<int>& vals, const vector<pair<int, int>>& groups, int target)
{
    int l = 0;
    int r = groups.size()-1;
    int res = 0;
    while(l <= r)
    {
        int mid = l + (r-l)/2;

        if(target < vals[groups[mid].first])
        {
            r = mid-1;
            res = mid;
        }
        else if(target > vals[groups[mid].second])
        {
            l = mid + 1;
        }
        else if(target >= vals[groups[mid].first] && target < vals[groups[mid].second])
        {
            return mid;
        }
        else
        {
            l = mid + 1;
            res = mid + 1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> vals(m);

    for(int i = 0; i < m; ++i)
    {
        cin>>vals[i];
    }
    sort(vals.begin(), vals.end());

    vector<pair<int, int>> groups;
    groups.push_back({0, m-1});

    while(k--)
    {
        int target;
        cin>>target;

        int groupIndex = FindGroup(vals, groups, target);
        auto it = lower_bound(vals.begin() + groups[groupIndex].first, vals.begin() + groups[groupIndex].second + 1, target + 1);
        cout<<*it<<"\n";

        // 그룹에 남은 하나 = 지우기
        if(groups[groupIndex].first == groups[groupIndex].second)
        {
            groups.erase(groups.begin() + groupIndex);
        }
        else
        {
            int index = it - vals.begin();
            if(index == groups[groupIndex].first) ++groups[groupIndex].first;
            else if(index == groups[groupIndex].second) --groups[groupIndex].second;
            else // 그룹 분리
            {
                groups.insert(groups.begin() + groupIndex + 1, {index+1, groups[groupIndex].second});
                groups[groupIndex].second = index-1;
            }
        }
    }
}
