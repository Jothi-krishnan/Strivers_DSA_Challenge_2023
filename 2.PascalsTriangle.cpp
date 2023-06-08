#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> printPascal(int n)
{
   vector<vector<long long>> ans;

   for(int i = 1; i<= n; i++)
   {
     vector<long long> curr;
     long long tmp = 1;
     for(int k = 1; k<= i; k++)
     {
         curr.push_back(tmp);
         tmp *= (i - k);
         tmp /= (k);
     }  
     ans.push_back(curr);
   } 

   return ans;
}


void solve()
{
    int n;
    cin>>n;

    vector<vector<long long>> ans = printPascal(n);

    for(int i  = 0; i<ans.size(); i++)
    {
        for(auto it: ans[i])
            cout<<it<<" ";


        cout<<"\n";
    }
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