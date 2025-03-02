class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int target,int i, int sum){
        if(i>=nums.size()){
            if(sum==target) return 1;
            else return INT_MIN;
        }
        if(sum+nums[i]>target) return dp[i][sum]=helper(nums,target,i+1,sum);
        if(dp[i][sum]!=-6000) return dp[i][sum];
        
        int take=1+helper(nums,target,i+1,sum+nums[i]);
        int leave=helper(nums,target,i+1,sum);

        return dp[i][sum]=max(take,leave);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        dp.resize(nums.size()+1,vector<int>(target+1,-6000));

        int ans=helper(nums,target,0,0);
        if(ans<=0) return -1;
        else return ans-1;
    }
};