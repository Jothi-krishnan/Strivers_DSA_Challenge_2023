#include<bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    int count = k;
    int ans = 0;
    int i = 0;
    int j = 0;

    for(; j<n; j++)
    {
        while(j< n && (count > 0 || arr[j] == 1))
        {
            if(arr[j] == 0)
                count--;
            j++;
        }
        j--;
        ans = max(ans, j - i+1);

        while(count <= 0)
        {
            if(arr[i] == 0)
                count++;

            i++;
        }
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

        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin>>arr[i];

        int k;
        cin>>k;

        cout<<longestSubSeg(arr, n, k)<<"\n";
    }
    return 0;
}