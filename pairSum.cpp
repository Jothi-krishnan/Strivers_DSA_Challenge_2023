#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   map<int, int> mp;
   vector<vector<int>> res;
   sort(arr.begin(),arr.end());
   for(int i = 0; i<n; i++)
   {
       if(mp.find(s - arr[i]) != mp.end())
       {
         for (int j = 0; j < mp[s - arr[i]]; j++) {
           vector<int> curr;
           curr.push_back(s - arr[i]);
              curr.push_back(arr[i]);
              
                res.push_back(curr);
              
           }
       }

       mp[arr[i]]++;
   }

   sort(res.begin(), res.end());
   return res;
}

void solve()
{
    int n, s;
    cin>>n>>s;

    vector<int> a(n);
    
    for(int i =0; i<n; i++)
        cin>>a[i];

    vector<vector<int>> res = pairSum(a, s);

}

int main()
{
    int t;
    // cin>>t;

    while(t--)  
    {
        solve();
    }
}