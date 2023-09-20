#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	
	int left = 0, right = n-1;

	while(right >= left)
	{
		int mid = left + (right - left)/2;

		if((mid <= n-2 && arr[mid] != arr[mid + 1]) && ( mid >= 1 && arr[mid] != arr[mid-1]))
			return arr[mid];
		else if(mid == 0 || mid == n-1)
			return arr[mid];

		int leftsize = 0, rightsize = 0;

		if(mid <= n-2 && arr[mid] == arr[mid+1])
		{
			leftsize = mid;
			rightsize = n - mid - 1;
		}
		else{
			leftsize = mid - 1;
			rightsize = n - mid;
		}

		if(leftsize % 2 == 1)
			right = mid - 1;
		else{
			left = mid + 1;
		}
	} 

	return -1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i= 0; i<n; i++)
        cin>>arr[i];

    cout<<singleNonDuplicate(arr)<<"\n";
}