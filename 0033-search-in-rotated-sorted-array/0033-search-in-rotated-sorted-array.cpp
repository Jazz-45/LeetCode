class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;

            //Left Half is Sorted
            if(nums[low]<=nums[mid]){
                if(target>= nums[low] && target<=nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            // Right Half is sorted
            else{
                if(target>= nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};