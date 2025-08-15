class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& matrix,int i,int j){
        int m=matrix.size();
        if(j<0 || j>=m) return 50000;
        if(i==m-1) return matrix[i][j];

        if(dp[i][j]!=50000) return dp[i][j];
        

        int down=helper(matrix, i + 1, j);
        int downLeft=helper(matrix, i + 1, j - 1);
        int downRight=helper(matrix, i + 1, j + 1);

        return dp[i][j]=matrix[i][j] + min({down, downLeft, downRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();

        dp.clear();
        dp.resize(m,vector<int>(m,50000));
        
        // int ans=INT_MAX;
        // for (int col=0;col<m;col++) {
        //     ans = min(ans, helper(matrix, 0, col));
        // }
        // Memoization
        // return ans;

        //Tabulation
        // for(int j=0;j<m;j++) dp[m-1][j]=matrix[m-1][j];

        // for(int i=m-2;i>=0;i--){
        //     for(int j=0;j<m;j++){
        //         int down = dp[i+1][j];
        //         int downLeft = (j > 0) ? dp[i+1][j-1] : INT_MAX;
        //         int downRight = (j < m-1) ? dp[i+1][j+1] : INT_MAX;
        //         dp[i][j] = matrix[i][j] + min({down, downLeft, downRight});
        //     }
        // }

        // int ans=INT_MAX;
        // for(int i=0;i<m;i++) ans=min(ans,dp[0][i]);
        // return ans;

        // Space Optimization
        vector<int> prev(m,50000),curr(m,50000);
        for(int j=0;j<m;j++) curr[j]=matrix[m-1][j];
        prev=curr;

        for(int i=m-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int down = prev[j];
                int downLeft = (j > 0) ? prev[j-1] : INT_MAX;
                int downRight = (j < m-1) ? prev[j+1] : INT_MAX;
                curr[j] = matrix[i][j] + min({down, downLeft, downRight});
            }
            prev=curr;
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++) ans=min(ans,prev[j]);
        return ans;
    }
};