#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int maxLen = 1;
    map<int, int> mp;
    for(int i= 0; i<n; i++)
        mp[arr[i]] = 1;

    for(int i = 0; i<n; i++)
    {
        if(mp.find(arr[i] - 1) == mp.end())
        {
            int curr = 1;
            int num = arr[i];

            while(mp.find(num +1) != mp.end())
            {
                curr += 1;
                num += 1;
            }

            maxLen = max(maxLen, curr);
        }
    }

    return maxLen;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];

        cout<<lengthOfLongestConsecutiveSequence(arr, n)<<"\n";
    }
    return 0;
}