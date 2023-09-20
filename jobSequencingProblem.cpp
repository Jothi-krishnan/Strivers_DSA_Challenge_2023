#include<bits/stdc++.h>
using namespace std;

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    vector<vector<int>> job = jobs;

    int n = job.size();
    sort(job.begin(), job.end(), [&](vector<int>a, vector<int>b){
       return a[2] > b[2];
    });

    int maxi = job[0][1];
    
    for(int i = 1; i<n; i++)
        maxi = max(maxi, job[i][1]);

    vector<int> job_taken(maxi+1, -1);

    int jobs_done = 0;
    int profit = 0;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = job[i][1]; j> 0; j--)
        {
            if(job_taken[j] == -1)
            {
                jobs_done++;
                profit += job[i][2];
                job_taken[j] = job[i][0];
                break;
            }
        }
    }

    return { jobs_done, profit };
}