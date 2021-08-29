#include<bits/stdc++.h>
using namespace std;

/*
In a grid of size m x n, each cell has a value.
Input: start and end point of the path, m and n
Output: number of unique paths to reach the end point
*/

class Solution {
public:
    
    int sol(int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if((i==(m-1)) && (j==(n-1)))
            return 1;
        if((i>=m) || (j>=n))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
            return dp[i][j]=(sol(m,n,i+1,j,dp)+sol(m,n,i,j+1,dp));
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int i=0,j=0;
        return sol(m,n,i,j,dp);
    }
};