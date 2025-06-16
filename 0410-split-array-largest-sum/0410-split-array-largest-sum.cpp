class Solution {
public:

    bool splitSum(vector<int>& nums, int k,int mid){
        
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(splitSum(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return (int)low;
    }
};