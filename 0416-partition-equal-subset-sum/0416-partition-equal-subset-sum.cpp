class Solution {
public:
    vector<vector<int>> dp;
    bool helper(vector<int>& nums , int i, int sum, int target){
        if(i==nums.size()) return false;

        if(sum==target) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=helper(nums,i+1,sum+nums[i],target);
        bool leave=helper(nums,i+1,sum,target);
        return dp[i][sum]=take||leave;
    }

    bool canPartition(vector<int>& nums) {
        // Subset sum with target = sum/2
        int sum=0;
        for(int x: nums) sum+=x;
        if(sum%2==1) return false;

        dp.resize(nums.size(),vector<int>(sum,-1));
        return helper(nums,0,0,sum/2);
    }
};