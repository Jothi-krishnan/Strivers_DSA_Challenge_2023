#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        while(arr[i] != i+1)
        {
            int idx = arr[i] - 1;
            if(arr[idx] == arr[i])
                return arr[idx];
            
            swap(arr[i], arr[idx]);
        }
    }
    
    return 0;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i =0; i<n; i++)
        cin>>a[i];

    cout<<findDuplicate(a, n)<<"\n";

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