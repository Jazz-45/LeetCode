class Solution {
public:
    string largestOddNumber(string nums) {
        int n=nums.length();
        string ans="";
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            char ch=nums[i];
            if((ch-'0')%2==1){
                idx=i;
                break;
            }
        }
        if(idx==-1) return ans;
        for(int i=0;i<=idx;i++) ans+=nums[i];
        return ans;
    }
};