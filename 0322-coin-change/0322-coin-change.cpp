class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& coins, int amount,int i){
        if(i==coins.size()){
            if(amount==0) return 0;
            else return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(amount-coins[i]<0) return dp[i][amount]=helper(coins,amount,i+1);
        int take=helper(coins,amount-coins[i],i);
        if(take==INT_MAX) return dp[i][amount]=helper(coins,amount,i+1);

        int leave=helper(coins,amount,i+1);
        return dp[i][amount]=min(take+1,leave);
    }
    int coinChange(vector<int>& coins, int amount) {

        
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,amount,0);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};