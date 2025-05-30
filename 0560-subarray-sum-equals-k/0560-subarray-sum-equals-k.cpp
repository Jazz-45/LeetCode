class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m; // {sum,count}
        m[0]=1;

        int sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remove=sum-k;
            count+=m[remove];
            m[sum]+=1;
        }
        return count;
    }
};