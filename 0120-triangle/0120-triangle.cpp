class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& triangle,int i,int j){
        int m=triangle.size();
        if (i==m-1) return triangle[i][j];

        if(dp[i][j]!=INT_MAX) return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(helper(triangle,i+1,j+1),helper(triangle,i+1,j));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(),n=triangle[m-1].size();
        dp.clear();
        dp.resize(m,vector<int>(n,INT_MAX));
        return helper(triangle,0,0);
    }
};