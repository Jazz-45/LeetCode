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
        // return helper(grid,m-1,n-1);

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) dp[i][j]=grid[0][0];
        //         else{
        //             int top=(i>0) ? dp[i-1][j] : INT_MAX;
        //             int left=(j>0) ? dp[i][j-1] : INT_MAX;
        //             dp[i][j]=grid[i][j]+min(top,left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // Space optimization
        vector<int> curr(n,INT_MAX), prev(n,INT_MAX);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[0]=grid[0][0];
                else{
                    int top=(i>0) ? prev[j] : INT_MAX;
                    int left=(j>0) ? curr[j-1] : INT_MAX;
                    curr[j]=grid[i][j]+min(top,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};