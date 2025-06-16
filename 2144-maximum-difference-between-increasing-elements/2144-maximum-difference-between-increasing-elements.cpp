class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int diff = -1;

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > minVal) {
                diff = max(diff, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }

        return diff;
    }
};
