class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& obstacleGrid,int m,int n){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;

        if(obstacleGrid[m][n]==1) return dp[m][n]=0;
        if(dp[m][n]!=0) return dp[m][n];

        return dp[m][n]=helper(obstacleGrid,m-1,n)+helper(obstacleGrid,m,n-1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;

        dp.clear();
        dp.resize(m,vector<int>(n,0));

        return helper(obstacleGrid,m-1,n-1);
    }
};