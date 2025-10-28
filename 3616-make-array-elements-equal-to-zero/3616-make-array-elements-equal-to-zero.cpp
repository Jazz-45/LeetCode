class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];

        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]+nums[i];

        int selections=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(prefix[i]==suffix[i]) selections+=2;
                if(abs(prefix[i]-suffix[i])==1) selections++;
            }
        }

        return selections;
    }
};