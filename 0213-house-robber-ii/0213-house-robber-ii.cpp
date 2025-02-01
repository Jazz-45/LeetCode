class Solution {
public:
    /* 
        Earlier we assumed the array to be 1,2,3,1
        Now since we can't rob 1st and last simultaneously
        We will consider ->
        max of  [1,2,3] , [2,3,1]
    */


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        // Case 1: Rob first house, but not the last
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        int max1 = dp[n - 2];

        // Case 2: Rob second house, but not the first
        dp[0] = 0;  // Since we skip the first house
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + (i > 1 ? dp[i - 2] : 0));
        }
        int max2 = dp[n - 1];

        return max(max1, max2);
    
    }
};