class Solution {
public:
    vector<vector<int>> dp;
    int helper(int m,int n){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;

        if(dp[m][n]!=0) return dp[m][n];

        return dp[m][n]=helper(m-1,n)+helper(m,n-1);
    }
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(m,vector<int>(n,0));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        // return dp[m-1][n-1];
        // return helper(m-1,n-1);


        // Space optimization
        vector<int> prev(n, 1), curr(n, 1); // first row is all 1's

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                curr[j] = curr[j-1] + prev[j];
            }
            prev = curr; // move to next row
        }
        return prev[n-1];
    }
};