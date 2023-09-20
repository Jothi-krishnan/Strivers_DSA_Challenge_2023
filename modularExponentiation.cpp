#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int modularExponentiation(int a, int y, int p) {
   long long res = 1;
   long long x =a ;
    while (y > 0)
    {
      if (y%2==1)
        res = (res * x) % p;
 
      y = y/2; 
	  x = (x * x) % p;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int x, y, m;
        cin>>x>>y>>m;

        cout<<modularExponentiation(x, y, m)<<"\n";
    }
    return 0;
}