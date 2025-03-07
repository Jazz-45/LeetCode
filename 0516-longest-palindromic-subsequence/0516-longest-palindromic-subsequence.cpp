class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& text1, string& text2,int i , int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+lcs(text1,text2,i-1,j-1);
        else{
            return dp[i][j]=max(lcs(text1,text2,i-1,j),lcs(text1,text2,i,j-1));
        }
    }

    int longestPalindromeSubseq(string s) {
        int i=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        dp.resize(i,vector<int> (i,-1));
        return lcs(s,t,i-1,i-1);
    }
};