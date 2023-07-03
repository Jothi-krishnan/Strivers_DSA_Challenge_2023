#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int idx;
};

bool cmp(struct meeting m1, struct meeting m2)
{
    if(m2.end > m1.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.idx < m2.idx) return true;

    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct meeting meet[n];
    for (int i = 0; i < n; i++) {
    meet[i].start = start[i];
    meet[i].end = end[i];
    meet[i].idx = i+ 1;
    }
    sort(meet, meet + n, cmp);

    int end_time = INT_MIN;
    vector<int> ans;

    for(int i = 0; i<n; i++)
    {
        if(meet[i].start > end_time)
        {
            ans.push_back(meet[i].idx);
            end_time = meet[i].end;
        }
        else
            continue;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> start(n), end(n);
        for(int i = 0; i<n; i++)
            cin>>start[i];

        for(int i = 0; i<n; i++)
            cin>>end[i];

        vector<int> ans = maximumMeetings(start, end);

        for(int i = 0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        
        cout<<"\n";
    }

    return 0;
}