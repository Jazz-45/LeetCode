class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid,int m,int n){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return INT_MAX;

        if(dp[m][n]!=-1) return dp[m][n];

        return dp[m][n]=grid[m][n]+min(helper(grid,m-1,n),helper(grid,m,n-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.clear();
        dp.resize(m,vector<int>(n,-1));
        return helper(grid,m-1,n-1);
    }
};