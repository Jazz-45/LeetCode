class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int k=nums.size();

        unordered_set<int> s;

        for(int i=0;i<k;i++){
            if(s.find(nums[i])==s.end()) s.insert(nums[i]);
            else s.erase(nums[i]);
        }

        if(s.size()==0) return true;
        else return false;
    }
};