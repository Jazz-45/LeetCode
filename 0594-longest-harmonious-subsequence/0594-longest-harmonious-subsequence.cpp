class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;

        for(int x: nums) m[x]++;

        int longestSeq=0;
        for(int i=0;i<n;i++){

            if(m.find(nums[i]+1)!=m.end()){
                longestSeq=max(longestSeq,m[nums[i]]+m[nums[i]+1]);
            }
        }

        return longestSeq;
    }
};