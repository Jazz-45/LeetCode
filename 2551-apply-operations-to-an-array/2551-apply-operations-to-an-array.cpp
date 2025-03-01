class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();

        // Performing Operations
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        // Shifting zeros  
        int j=0;  
        while(j<n){  
            if(nums[j]==0){  
                int k=j+1;  
                while(k<n && nums[k]==0) k++;
                if(k<n) swap(nums[j],nums[k]);  
                else  break;  // No more non-zero elements to swap  
            }  
            j++;  
        }
        return nums;
    }
};