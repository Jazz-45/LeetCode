class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums,int i,vector<int> temp){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //leave
        helper(nums,i+1,temp);

        // Take
        temp.push_back(nums[i]);
        helper(nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();

        // Clearing the global variable
        ans.clear();
        vector<int> temp={};
        helper(nums,0,temp);

        return ans;
    }
};