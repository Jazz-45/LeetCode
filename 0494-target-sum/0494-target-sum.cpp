class Solution {
public:

    vector<vector<int>> dp;
    int total;
    int helper(vector<int>& nums,int idx, int target,int currSum){
        if(idx>=nums.size()){
            if(currSum==target) return 1;
            else return 0;
        }
        if(dp[idx][currSum+total]!=6969) return dp[idx][currSum+total];
        int add=helper(nums,idx+1,target,currSum+nums[idx]);
        int subtract=helper(nums,idx+1,target,currSum-nums[idx]);
        return dp[idx][currSum+total]=add+subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        for(int ele:nums) total+=ele;
        dp.resize(nums.size(),vector<int>(2*total+1,6969));
        return helper(nums,0,target,0);
    }
};