class Solution {
public:
    vector<int> dp;
    bool helper(int idx, vector<int>& nums) {
        if (idx >= nums.size() - 1)
            return true;
        if (dp[idx]!=-1) return dp[idx];
        bool ans = false;
        if(nums[idx]>=nums.size()-1-idx) return true;
        for (int i = 1; i <= nums[idx]; i++) {
            ans = ans || helper(idx + i, nums);
        }
        return dp[idx]=ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // Greedy Approach
        // bool flag=true;
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i]!=0) continue;
        //     flag=false;
        //     int count=1;
        //     int j=i-1;
        //     while(j>=0){
        //         if(nums[j]>count){
        //             flag=true;
        //             break;
        //         }else{
        //             count++;
        //             j--;
        //         }
        //     }
        //     i=j;
        // }
        // return flag;
        dp.resize(n, -1);
        return helper(0, nums);
    }
};