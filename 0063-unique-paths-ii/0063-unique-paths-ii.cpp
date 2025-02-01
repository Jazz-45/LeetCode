class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();

        // If starting or ending cell is an obstacle, return 0
        if (arr[0][0] == 1 || arr[m-1][n-1] == 1) return 0;

        // Bottom - Up
        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (arr[i][j] == 1) continue;  // If obstacle, skip
                if (i > 0) dp[i][j] += dp[i - 1][j];  // From top
                if (j > 0) dp[i][j] += dp[i][j - 1];  // From left
            }
        }
        return dp[m-1][n-1];
    }
};