#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount) 
{
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int n = amount;

    int j = 8;
    int total_coins = 0;

    while(j>= 0)
    {
        int curr_num = n/coins[j];
        n -= curr_num*coins[j];
        total_coins += curr_num;
        j--;
    }

    return total_coins;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int amount;
        cin>>amount;

        cout<<findMinimumCoins(amount)<<"\n";
    }
}
