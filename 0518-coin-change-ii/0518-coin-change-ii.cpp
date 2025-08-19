using u128 = unsigned __int128;

class Solution {
public:
    vector<vector<u128>> dp;
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
        dp.resize(n,vector<u128>(amount+1,0));
        //return helper(amount,coins,n-1);

        //Tabulation
        //Base Case
        for(int i=0;i<n;i++) dp[i][0]=1;
        for (int t=0;t<=amount;t++) dp[0][t]=(t%coins[0]==0);
        //Other Cases
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                u128 notTake=dp[i-1][t];
                u128 take=0;
                if(coins[i]<=t) take=dp[i][t-coins[i]];
                dp[i][t]=notTake+take;
            }
        }
        return (int)dp[n-1][amount];


    }
};