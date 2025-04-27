class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();

        // Sliding Window approach
        int i=0,j=2;
        int count=0;

        while(j<n){
            if(2*(nums[i]+nums[j])==nums[i+1]) count++;
            i=i+1;
            j=j+1;
        }
        return count;
    }
};