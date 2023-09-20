#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long mx = 0;
    long long curr = 0;

    for(int i = 0; i<n; i++)
    {
        curr = max(curr+  (long long) arr[i], (long long)arr[i]);
        mx =  max(mx, curr);
    }

    return mx;
}

void solve()
{
    int n;
    cin>>n;

    int a[n];
    
    for(int i =0; i<n; i++)
        cin>>a[i];

    cout<<maxSubarraySum(a, n)<<"\n";

}

int main()
{
    int t;
    cin>>t;

    while(t--)  
    {
        solve();
    }
}