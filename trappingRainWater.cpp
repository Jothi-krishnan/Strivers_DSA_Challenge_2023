#include<bits/stdc++.h>
using namespace std;

long long getTrappedWater(long long *arr, int n){
    long long left = 0, right = n-1;
    long long left_max = 0, right_max = 0;

    long long ans = 0;

    while(left < right)
    {
        left_max = max(left_max, arr[left]);
        right_max = max(right_max, arr[right]);

        if(left_max <= right_max)
        {
            ans += left_max - arr[left];
            left++;
        }
        else{
            ans += right_max - arr[right];
            right--;
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

        long long a[n];
        for(int i= 0; i<n; i++)
            cin>>a[i];

        cout<<getTrappedWater(a, n)<<"\n";
    }
}