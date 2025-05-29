class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        
        // i->left j->mid;k->right
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // Very Imp
            int j=i+1,k=n-1;
            while(j<k){
                int currSum=nums[i]+nums[j]+nums[k];
                if(currSum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(currSum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};