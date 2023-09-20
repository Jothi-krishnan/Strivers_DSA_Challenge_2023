#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();

    map<int, int> mp;
    int curr = 0;
    int count = 0;

    for(int i = 0; i<n; i++)
    {
        curr ^= arr[i];

        if(curr == x)
            count++;

        if(mp.find(curr^x) != mp.end())
        {
            count += mp[curr^x];
        }

        mp[curr]++;
    }

    return count;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];

        cout<<subarraysXor(arr, x)<<"\n";
    }
    return 0;
}