#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input)
{
    int maxLen = 1;
    bool flag = false;
    map<char, int> mp;
    int lastidx = 0;
    int n = input.length();

    for(int i = 0; i<n; ++i)
    {
        if(mp.find(input[i]) != mp.end())
        {
            flag = true;
            if(mp[input[i]] >= lastidx)
            {
                int curr_len = i - lastidx;
                maxLen = max(maxLen, curr_len);
                lastidx = mp[input[i]] + 1;
            }
        }

        mp[input[i]] = i;
    }    
    
    if(flag == false)
        return n;
    
    return maxLen;
}

int main()
{
    string s;
    cin>>s;

    cout<<uniqueSubstrings(s)<<"\n";
    return 0;
}