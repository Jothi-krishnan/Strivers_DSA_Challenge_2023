#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    map<long long, pair<int, int>> mp;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            int num = arr[j] + arr[i];
            if(mp.find(target - num) != mp.end() && mp[target - num].first != i && mp[target - num].second != j)
                return "Yes\n";
            
            mp[num] = {i, j};
        }
    }

    return "No\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, target;
        cin>>n>>target;

        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];

        cout<<fourSum(arr, target, n);
    }
}
