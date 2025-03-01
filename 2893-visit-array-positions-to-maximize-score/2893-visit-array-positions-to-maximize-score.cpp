class Solution {
public:
    vector<vector<long long>> dp;
    long long helper(vector<int>& nums, int x, int i,int parity){

        if(i>=nums.size()) return 0;

        long long take,leave;

        if(dp[i][parity]!=-1) return dp[i][parity];
        if(nums[i]%2==parity) take=nums[i]+helper(nums,x,i+1,nums[i]%2);
        else take=(nums[i]-x)+helper(nums,x,i+1,nums[i]%2);

        leave=helper(nums,x,i+1,parity);

        return  dp[i][parity]=max(take,leave);
    }

    long long maxScore(vector<int>& nums, int x){

        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1)); // Initialize memoization table
        
        return nums[0]+helper(nums,x,1,nums[0]%2);
    }
};