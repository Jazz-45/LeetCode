class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        // Trimming the search space to low+1 to high-1 to prehandle edge cases
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            
            //we are in the left:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                    || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                //eliminate the left half:
                low = mid + 1;
            }
            //we are in the right:
            else {//eliminate the right half:
                high = mid - 1;
            }
        }
        return -1;
    }
};