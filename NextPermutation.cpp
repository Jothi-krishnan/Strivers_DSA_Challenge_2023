#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& permutation, int n)
{
   int idx = -1;
   for(int i = n-2; i>= 0; i--)
   {
       if(permutation[i] < permutation[i+1])
       {
           idx = i;
           break;
       }
   }

   if(idx == -1)
   {
       reverse(permutation.begin(), permutation.end());
       return permutation;
   }

    for(int i = n-1; i> idx; i--)
    {
        if(permutation[i] > permutation[idx])
        {
            swap(permutation[i], permutation[idx]);
            break;
        }
    }

    int left = idx + 1;
    int right = n - 1;

    while(right > left)
    {
        swap(permutation[right], permutation[left]);
        right--;
        left++;
    }
    return permutation;
}


void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i<n; i++)
        cin>>a[i];

    vector<int> nextP = nextPermutation(a, n);

    for(int i = 0; i<n; i++)
        cout<<nextP[i]<<" ";

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