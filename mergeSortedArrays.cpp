#include<bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    int i = n - 1;
	int j = m - 1;
	int k = (n + m) -1;

	while(i >= 0 && j>= 0)
	{
		if(arr1[i] < arr2[j])
		{
			arr1[k] = arr2[j];
			k--;
			j--;
		}
		else{
			arr1[k] = arr1[i];
			i--;
			k--;
		}   
	}

	while(i >= 0)
	{
		arr1[k] = arr1[i];
		i--;
		k--;
	}

	while(j >= 0)
	{
		arr1[k] = arr2[j];
		j--;
		k--;
	}
	return arr1;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> a(n+m, 0), b(m);
    for(int i = 0; i<n; i++)
        cin>>a[i];

    for(int i = 0; i<m; i++)
        cin>>b[i];

    vector<int> merged = ninjaAndSortedArrays(a, b, n, m);

    for(int i = 0; i<merged.size(); i++)
        cout<<merged[i]<<" ";

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