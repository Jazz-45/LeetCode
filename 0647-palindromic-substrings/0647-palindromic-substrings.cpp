class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();

        vector<vector<int>> dp(n,vector<int>(n,1));

        int count=n;
        for(int k=1;k<n;k++){
            for(int i=0,j=k;i<=n-1-k,j<=n-1;i++,j++){
                if(s[i]!=s[j]) dp[i][j]=0;
                else{
                    //if (i to j) substring of len=2
                    if(j==i+1){
                        dp[i][j]=1;
                        count++;
                    }
                    else{
                        if(dp[i+1][j-1]==1){
                             dp[i][j]=1;
                             count++;
                        }
                        else dp[i][j]=0;
                    }
                }
            }
        }

        return count;
        
    }
};