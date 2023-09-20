#include <bits/stdc++.h> 
using namespace std;

long long merge(long long *a, long long *tmp, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;
    long long invCount = 0;

    while(i<= mid-1 && j<= right)
    {
        if(a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        } else {
          tmp[k++] = a[j++];
          invCount += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        tmp[k++] = a[i++];
    }

    while(j <= right)
    {
        tmp[k++] = a[j++];
    }

    for(int idx = left; idx<= right; idx++)
    {
        a[idx] = tmp[idx];
    }
    
    return invCount;

}

long long _mergeSort(long long *a, long long* tmp, int left, int right)
{
    int mid, invCount = 0;
    
    if(right > left)
    {
        mid = (left + right)/2;

        invCount += _mergeSort(a, tmp, left, mid);
        invCount += _mergeSort(a, tmp, mid + 1, right);

        invCount += merge(a, tmp, left, mid + 1, right);
    }

    return invCount;
}
long long getInversions(long long *arr, int n){
    long long a[n];
    for(int i= 0; i<n; i++)
        a[i] = arr[i];
    
    long long tmp[n];

    return _mergeSort(a, tmp, 0, n-1);
}


int main()
{
    int n;
    cin>>n;

    long long arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    cout<<getInversions(arr, n)<<"\n";
}