#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	if(n< 3)
		return ans;


	sort(arr.begin(), arr.end());

	for(int i = 0; i<n-2; i++)
	{
		int start = i + 1;
		int end = n - 1;
		
		while(start < end)
		{
			int sum = arr[i] + arr[start] + arr[end];
			if(sum == K)
			{
					ans.push_back({arr[i], arr[start], arr[end]});

					start++;
					end--;
					while (start < n && arr[start] == arr[start - 1])
						start++;

					while (end > i && arr[end] == arr[end + 1])
						end--;
			}
			else if(sum > K)
				end--;
			else{
				start++;
			}
		}
		
		while(i < n -1 && arr[i] == arr[i+1])
			i++;
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
        for(int i= 0; i<n; i++)
            cin>>arr[i];

        int K;
        cin>>K;

        vector<vector<int>> ans = findTriplets(arr, n, K);

        if(ans.size() == 0)
        {
            cout<<"-1\n";
            continue;
        }

        for(int i = 0; i<ans.size(); i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
        }
    }
}