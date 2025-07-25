class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(nums[i]>0) s.insert(nums[i]);
        }

        if(s.size()==0) return *max_element(nums.begin(),nums.end());

        int sum=0;
        for(auto x: s) sum+=x;
        return sum;
    }
};