class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        int upperBound=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                upperBound=mid;
                high=mid-1;
            }
            else{ // nums[mid]<target
                low=mid+1;
            }
        }

        return (upperBound==-1) ? nums.size() : upperBound;
        
    }
};