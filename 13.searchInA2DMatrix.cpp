#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool search(vector<vector<int>>& mat, int target, int m, int row)
{
    int low = 0;
    int high = m-1;
    
    while(low <= high)
    {
        int mid = (low + high)/2;

        if(mat[row][mid] == target)
            return true;
        else if(mat[row][mid] > target)
            high = mid -1;
        else{
            low = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = n - 1;

    while(high >= low)
    {
        int mid = (low + high)/2;

        if(mat[mid][0] == target || mat[mid][m-1] == target)
            return true;

        if(mat[mid][0] < target && mat[mid][m-1] > target)
            return search(mat, target, m, mid);
        
        if(mat[mid][0] > target)
            high = mid -1;
        else{
            low = mid + 1;
        }
    }

    return false;
}

int main()
{
    int n, m, target;
    cin>>n>>m>>target;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin>>mat[i][j];
    }

    cout<<searchMatrix(mat, target)<<"\n";
    return 0;
}