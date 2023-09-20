#include<bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    int left = 0, right = n-1;

    int i = 0;

    while(i <= right)
    {
        if(arr[i] == 0)
        {
            swap(arr[i], arr[left]);
            left++;
        }
        else if(arr[i] == 2)
        {
            swap(arr[i], arr[right]);
            right--;
            continue;
        }
        i++;
    }

}


void solve()
{
    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];

    sort012(a, n);
    
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<"\n";
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