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
        // return helper(triangle,0,0);

        // Tabulation
        // Base case Fill-up
        // for(int j=0;j<triangle[m-1].size();j++){
        //     dp[m-1][j]=triangle[m-1][j];
        // }
        // for(int i=m-2;i>=0;i--){
        //     for(int j=0;j<triangle[i].size();j++){
        //         dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        //     }
        // }
        // return dp[0][0];

        //Space Optimization
        vector<int> prev(n,INT_MAX),curr(n,INT_MAX);
        for(int j=0;j<triangle[m-1].size();j++){
            curr[j]=triangle[m-1][j];
        }
        prev=curr;

        for(int i=m-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                curr[j]=triangle[i][j]+min(prev[j],prev[j+1]);
            }
            prev=curr;
        }
        return prev[0];



    }
};