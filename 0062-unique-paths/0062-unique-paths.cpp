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
        return helper(m-1,n-1);
    }
};