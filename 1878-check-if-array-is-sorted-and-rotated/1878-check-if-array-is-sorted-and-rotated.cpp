class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        short count=0;
        if(nums[n-1]>nums[0]) count++;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) count++;
        }
        if(count>1) return false;
        else return true;
    }
};