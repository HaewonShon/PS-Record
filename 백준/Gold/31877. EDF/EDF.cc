#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<tuple<int, int>> pq;

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i)
    {
        int t, d;
        cin>>t>>d;
        pq.emplace(-d, t);
    }

    int m;
    cin>>m;
    vector<tuple<int, int, int>> addedJobs;

    for(int i = 0; i < m; ++i)
    {
        int w, t, d;
        cin>>w>>t>>d;
        addedJobs.emplace_back(w, t, d);
    }
    sort(addedJobs.begin(), addedJobs.end()); // w순 정렬
    
    int currentTime = 0;
    int addedJobsIndex = 0;
    
    while(!pq.empty())
    {
        while(addedJobsIndex < m && get<0>(addedJobs[addedJobsIndex]) <= currentTime)
        {
            int t = get<1>(addedJobs[addedJobsIndex]);
            int d = get<2>(addedJobs[addedJobsIndex]);
            pq.emplace(-d, t);
            addedJobsIndex++;
        }

        auto p = pq.top();
        pq.pop();
        int t = get<1>(p);
        int d = -get<0>(p);
        
        int expectedEndTime = currentTime + t;
        if(expectedEndTime > d)
        {
            cout<<"NO";
            return 0;
        }

        if(addedJobsIndex < m && get<0>(addedJobs[addedJobsIndex]) < expectedEndTime)
        {
            expectedEndTime = get<0>(addedJobs[addedJobsIndex]);
            pq.emplace(-d, t - (expectedEndTime - currentTime));
        }
        currentTime = expectedEndTime;
    }

    while(addedJobsIndex < m)
    {
        int w = get<0>(addedJobs[addedJobsIndex]);
        if(w > currentTime)
            currentTime = w;

        int t = get<1>(addedJobs[addedJobsIndex]);
        int d = get<2>(addedJobs[addedJobsIndex]);

        int expectedEndTime = currentTime + t;
        if(expectedEndTime > d)
        {
            cout<<"NO";
            return 0;
        }
        currentTime = expectedEndTime;
        addedJobsIndex++;
    }
    cout<<"YES\n"<<currentTime;
}   