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

        int ans=INT_MAX;
        for (int col=0;col<m;col++) {
            ans = min(ans, helper(matrix, 0, col));
        }
        return ans;
    }
};