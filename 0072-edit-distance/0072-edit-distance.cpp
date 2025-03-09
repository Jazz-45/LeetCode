class Solution {
public:
    vector<vector<int>> dp;
    int helper(string a,string b,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(a[i]==b[j]) return dp[i][j]=helper(a,b,i-1,j-1);
        else{
            int add=1+helper(a,b,i,j-1);
            int remove=1+helper(a,b,i-1,j);
            int replace=1+helper(a,b,i-1,j-1);
            return dp[i][j]=min({add,remove,replace});
        }
    }
    int minDistance(string a, string b){
        int m=a.size(),n=b.size();
        dp.resize(m,vector<int>(n,-1));
        return helper(a,b,a.size()-1,b.size()-1);
    }
};