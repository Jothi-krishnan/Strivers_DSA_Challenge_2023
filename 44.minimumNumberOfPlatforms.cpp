#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int ans = 1;
    int curr = 1;
    int j = 0, i = 1;

    while(i< n && j< n)
    {
        if(at[i] <= dt[j])
        {
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }

        ans = max(ans, curr);
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

        int at[n], dt[n];
        for(int i = 0; i<n; i++)
            cin>>at[i];

        for(int i= 0; i<n; i++)
            cin>>dt[i];

        cout<<calculateMinPatforms(at, dt, n)<<"\n";
    }

    return 0;
}