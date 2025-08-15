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

        // return helper(obstacleGrid,m-1,n-1);
        for (int j=0;j<n;j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }
        // initialize first col
        for (int i=0;i<m;i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        // fill the rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

        vector<int> dp(n, 0);

        // Initialize first row
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[j] = 1;
        }

        // Process each row
        for (int i = 1; i < m; i++) {
            // First column: reset to 0 if obstacle
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            // Other columns
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j-1];
            }
        }

        return dp[n-1];
    }
};