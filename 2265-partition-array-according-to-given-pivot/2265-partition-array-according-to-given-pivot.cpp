class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l=nums.size();

        vector<int> smaller,greater;
        for(int i=0;i<l;i++) if(nums[i]<pivot) smaller.push_back(nums[i]);
        for(int i=0;i<l;i++) if(nums[i]>pivot) greater.push_back(nums[i]);

        int n=smaller.size(),m=greater.size();
        vector<int> ans;
        int diff=0;
        for(int i=0;i<smaller.size();i++) ans.push_back(smaller[i]);
        if(smaller.size()+greater.size()!=l){
            int diff=l-(n+m);
            while (diff--) ans.push_back(pivot);
        }
        for(int i=0;i<greater.size();i++) ans.push_back(greater[i]);

        return ans;
    }
};