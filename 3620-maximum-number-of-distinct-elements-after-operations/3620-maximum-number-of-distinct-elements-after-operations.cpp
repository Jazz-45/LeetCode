class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long curr = LLONG_MIN;  // current smallest assignable value
        int distinct = 0;

        for (long long num : nums) {
            long long low = num - k;
            long long high = num + k;
            long long assign = max(curr, low);

            if (assign <= high) {
                distinct++;
                curr = assign + 1;
            }
        }
        return distinct;
    }
};