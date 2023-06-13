#include<bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int count = 0;
	int num = 0;

	for(int i = 0; i<n; i++)
	{
		if(count == 0)
			num = arr[i];
		
		if(arr[i] == num)
			count++;
		else{
			count--;
		}
	}

	count = 0;
	for(int i= 0; i<n; i++)
	{
		if(arr[i] == num)
			count++;
	}

	if(count > n/2)
		return num;
	else{
		return -1;
	}
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<<findMajorityElement(arr, n)<<"\n";
    }
}