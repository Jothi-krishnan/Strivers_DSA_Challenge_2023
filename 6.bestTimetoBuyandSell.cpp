#include<bits/stdc++.h>
using namespace std;


int maximumProfit(vector<int>& prices)
{
    int mn = prices[0];
    int cost = 0;
    int n = prices.size();

    for(int i = 1; i<n; i++)
    {
        mn = min(prices[i], mn);
        cost = max(cost, prices[i] - mn);
    }

    return cost;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i =0; i<n; i++)
        cin>>a[i];

    cout<<maximumProfit(a)<<"\n";

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