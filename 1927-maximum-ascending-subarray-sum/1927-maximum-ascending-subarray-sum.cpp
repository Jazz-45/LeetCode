class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int sum = nums[0]; // Start with first element

        for (int j = 1; j < n; j++) {
            if (nums[j - 1] < nums[j]) { // Ascending condition
                sum += nums[j];
            } else {
                maxSum = max(maxSum, sum); // Update maxSum before resetting
                sum = nums[j]; // Reset sum to current element
            }
        }
        
        maxSum = max(maxSum, sum); // Final update after loop ends
        return maxSum;
    }
};
