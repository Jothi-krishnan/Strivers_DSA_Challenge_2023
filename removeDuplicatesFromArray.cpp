#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int j = 1;

	int i = 0;
	
	while(j < n)
	{
		if(arr[j] == arr[i])
		{
			j++;
		}
		else{
			swap(arr[i+1], arr[j]);
			i++;
			j++;
		}
	}

	return i+1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    cout<<removeDuplicates(arr, n)<<"\n";
}