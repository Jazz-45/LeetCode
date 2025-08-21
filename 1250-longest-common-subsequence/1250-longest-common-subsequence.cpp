class Solution {
public:
    vector<vector<int>> dp;
    int helper(string& text1, string& text2,int i,int j){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) return dp[i][j]=1+helper(text1,text2,i-1,j-1);
        else return dp[i][j]=max(helper(text1,text2,i,j-1),helper(text1,text2,i-1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        dp.clear();
        dp.resize(m+1,vector<int>(n+1,-1));
        //return helper(text1,text2,m-1,n-1);

        //Tabulation
        //Base Cases
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int j=0;j<=n;j++) dp[0][j]=0;

        //Other cases
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};