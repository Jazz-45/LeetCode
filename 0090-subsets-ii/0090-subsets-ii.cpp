class Solution {
public:
    void subset(vector<int>& nums,int idx,vector<int>& v,vector<vector<int>>& ans){

        ans.push_back(v);
        for(int i=idx;i<nums.size();i++){
            // pick
            if(i!=idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            subset(nums,i+1,v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());

        subset(nums,0,v,ans);
        return ans;

    }
};