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
        //int ans=helper(coins,amount,n-1);
        //return (ans>=1e9 ? -1 : ans);

        //Tabulation
        // Base Case
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }

        //Other Case
        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=amount;target++){
                int notTake=0+dp[idx-1][target];
                
                int take=1e9;
                if(coins[idx]<=target) take=1+dp[idx][target-coins[idx]];

                dp[idx][target]=min(take,notTake);
            }
        }
        //return (dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount]);


        // Space Optimization
        vector<int> prev(amount+1,-1),curr(amount+1,-1);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }

        //Other Case
        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=amount;target++){
                int notTake=0+prev[target];
                
                int take=1e9;
                if(coins[idx]<=target) take=1+curr[target-coins[idx]];

                curr[target]=min(take,notTake);
            }
            prev=curr;
        }
        return (prev[amount] >= 1e9 ? -1 : prev[amount]);
    }
};