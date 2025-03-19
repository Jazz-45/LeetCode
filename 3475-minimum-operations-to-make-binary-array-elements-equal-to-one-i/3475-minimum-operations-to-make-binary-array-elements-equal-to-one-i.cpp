class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i < n; i++) {
            // If current element is 0, flip the next 3 consecutive elements.
            if (nums[i] == 0) {
                // Check if there are at least 3 elements starting from index i.
                if (i + 2 >= n)
                    return -1;
                // Flip three consecutive elements.
                nums[i]   = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                operations++;
            }
        }
        return operations;
    }
};
