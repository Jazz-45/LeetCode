class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins, int amount,int idx){
        if(idx==0){
            if(amount % coins[idx]==0) return amount/coins[idx];
            else return 1e9; // 1e9 safer than INT_MAX
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int notTake=0+helper(coins,amount,idx-1);
        
        int take=1e9;
        if(coins[idx]<=amount) take=1+helper(coins,amount-coins[idx],idx);

        return dp[idx][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.clear();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans=helper(coins,amount,n-1);
        return (ans>=1e9 ? -1 : ans);
    }
};