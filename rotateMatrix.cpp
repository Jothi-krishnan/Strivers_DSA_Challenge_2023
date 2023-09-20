#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    int count = m*n;

    while(count > 0)
    {
        if(top >= bottom || left >= right)
            break;


        int tmp = mat[top + 1][left];

        for(int i = left; i<= right; i++)
        {
            int tmp2 = mat[top][i];
            mat[top][i] = tmp;
            tmp = tmp2;
            count--;
        }

        for(int i = top + 1; i<= bottom; i++)
        {
            int tmp2 = mat[i][right];
            mat[i][right] = tmp;
            tmp = tmp2;
            count--;
        }

        for(int i = right-1; i>= left; i--)
        {
            int tmp2 = mat[bottom][i];
            mat[bottom][i] = tmp;
            tmp = tmp2;
            count--;
        }

        for(int i = bottom -1; i>= top + 1; i--)
        {
            int tmp2 = mat[i][left];
            mat[i][left] = tmp;
            tmp = tmp2;
            count--;
        }
        if(count <= 0)
            break;
            
        top++;
        bottom--;
        left++;
        right--;
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> a(n, vector<int> (m, 0));
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            {
                cin>>a[i][j];
            }
    }

    rotateMatrix(a, n, m);

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout<<a[i][j]<<" ";


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