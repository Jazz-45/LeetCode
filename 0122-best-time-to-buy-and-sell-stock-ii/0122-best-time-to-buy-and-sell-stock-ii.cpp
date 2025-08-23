class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices,int idx,bool bought){
        if(idx==prices.size()) return 0;

        if(dp[idx][bought]!=-1) return dp[idx][bought];

        if(bought){ // Holding a stock
            return dp[idx][bought]=max(helper(prices,idx+1,true),prices[idx]+helper(prices,idx+1,false));
        }
        else{ // Not Holding a stock
            return dp[idx][bought]=max(helper(prices,idx+1,false),-prices[idx]+helper(prices,idx+1,true));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.clear();
        dp.resize(n+1,vector<int>(2,-1));
        return helper(prices,0,false);
    }
};