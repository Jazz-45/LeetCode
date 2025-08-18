class Solution {
public:
    vector<vector<int>> dp;
    bool helper(vector<int>& nums , int i, int sum, int target){
        if(i==nums.size()){
            if(sum==target) return true;
            else return false;
        }

        if(sum==target) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(sum+nums[i]>target) return dp[i][sum]=helper(nums,i+1,sum,target);
        bool take=helper(nums,i+1,sum+nums[i],target);
        bool leave=helper(nums,i+1,sum,target);
        return dp[i][sum]=take||leave;
    }

    bool canPartition(vector<int>& nums) {
        // Subset sum with target = sum/2
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;

        dp.resize(nums.size(),vector<int>(sum,-1));
        // return helper(nums,0,0,sum/2);
        int n = nums.size();

        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        // base case
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= sum/2; s++) {
                dp[i][s] = dp[i-1][s]; // don't take
                if (s >= nums[i-1]) {
                    dp[i][s] = dp[i][s] || dp[i-1][s - nums[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
};