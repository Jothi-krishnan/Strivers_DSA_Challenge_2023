#include<bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {

  int maxlen = 0;
  int csum = 0;
  map<int, int> idx;
  int n = arr.size();

  for(int i = 0; i<n; i++)
  {
    csum += arr[i];

    if(csum == 0)
    {
      maxlen = max(maxlen, i + 1);
      continue;
    }

    if(idx.find(csum) != idx.end())
    {
      int curr_len = i - idx[csum];
      maxlen = max(maxlen, curr_len);
      
    }
    else
      idx[csum] = i;
  }
  return maxlen;
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

        cout<<LongestSubsetWithZeroSum(arr)<<"\n";
        
    }
}