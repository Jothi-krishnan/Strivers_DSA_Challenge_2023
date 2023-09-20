#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];    
    int end = intervals[0][1];

    vector<vector<int>> res;
    res.push_back(intervals[0]);
    int idx = 0;

    for(int i = 1; i<n; i++)
    {
        if(intervals[i][0] <= res[idx][1])
        {
            res[idx][1]=max(res[idx][1],intervals[i][1]);
        }
        else{
            res.push_back({intervals[i]});
            idx++;
        }
    }

    return res;
}

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> a(n, vector<int> (2, 0));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<2; j++)
            cin>>a[i][j];
    }

    vector<vector<int>> merged = mergeIntervals(a);


    int sz = merged.size();

    for(int i = 0; i<sz; i++)
    {
        for(int j = 0; j<2; j++)
            cout<<a[i][j]<<" ";

        cout<<"\n";
    }
}

int main()
{
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
}