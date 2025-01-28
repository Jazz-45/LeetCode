class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        int i=0,j=1;

        while(i<n && j<n){
            if(nums[i]!=0){
                i++;
                j=j+1;
            }else{ // nums[i]==0
                if(nums[j]!=0){
                    swap(nums[i],nums[j]);
                    i++;
                    j=i+1;
                }else j++; // Both zero
                
            }
        }
        return;
    }
};