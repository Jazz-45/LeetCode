class Solution {
public:
    vector<vector<int>> dp;
    int helper(int amount, vector<int>& coins,int idx){
        if(amount==0) return 1;
        if(idx==0) return (amount%coins[idx]==0);

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int notTake=0+helper(amount,coins,idx-1);
        int take=0;
        if(coins[idx]<=amount) take=helper(amount-coins[idx],coins,idx);

        return dp[idx][amount]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.clear();
        dp.resize(n,vector<int>(amount+1,-1));
        return helper(amount,coins,n-1);
    }
};