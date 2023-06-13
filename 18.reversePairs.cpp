#include <bits/stdc++.h> 
using namespace std;

int merge(vector<int>&arr, vector<int>&tmp, int left, int mid, int right)
{
	int j = mid + 1;
	int invCount = 0;

	for(int i = left; i<= mid; i++)
	{
		while(j<=right && arr[i] > 2*arr[j])
			j++;
		
		invCount += (j - (mid + 1));
	}

	int i = left;
	j = mid + 1;
	int k = left;

	while(i <= mid && j<= right)
	{
		if(arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else{
			tmp[k++] = arr[j++];
		}
	}


	while( i<= mid)
	{
		tmp[k++] = arr[i++];
	}

	while(j<= right)
	{
		tmp[k++] = arr[j++];
	}


	for(int idx = left; idx<= right; idx++)
	{
		arr[idx] = tmp[idx];
	}

	return invCount;
	
}

int _mergeSort(vector<int> &arr, vector<int>&tmp, int left, int right)
{
	int mid, invCount = 0;

	if(right > left)
	{
		mid = (left + right)/2;
		invCount += _mergeSort(arr, tmp, left, mid);
		invCount += _mergeSort(arr, tmp, mid + 1, right);

		invCount += merge(arr, tmp, left, mid, right);
	}
	return invCount;
}

int reversePairs(vector<int> &arr, int n){
	vector<int> tmp(n);

	return _mergeSort(arr, tmp, 0, n-1);	
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

        cout<<reversePairs(arr, n)<<"\n";
    }
}

