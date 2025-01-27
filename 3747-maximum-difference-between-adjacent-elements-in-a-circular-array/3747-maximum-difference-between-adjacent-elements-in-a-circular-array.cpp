class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n=nums.size();
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==0) maxSum=max(maxSum,abs(nums[n-1]-nums[0]));
            else maxSum=max(maxSum,abs(nums[i]-nums[i-1]));
        }

        return maxSum;
    }
};