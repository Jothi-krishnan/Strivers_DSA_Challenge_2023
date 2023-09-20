#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int repeating = -1;
	int missing = -1;
	for(int i = 0; i<n; i++)
    {
        while(arr[i] != i+1)
        {
            int idx = arr[i] - 1;

            if(arr[i] == arr[idx])
            {
                repeating = arr[i];
				break;
            }
			else
            	swap(arr[i], arr[idx]);
        }
    }

	for(int i = 0; i<n; i++)
	{
		if(arr[i] != i +1)
			missing = i+1;
	}

    return {missing, repeating};
	
}


void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i =0; i<n; i++)
        cin>>a[i];

    pair<int, int> p = missingAndRepeating(a, n);

    cout<<p.first<<" "<<p.second<<"\n";

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