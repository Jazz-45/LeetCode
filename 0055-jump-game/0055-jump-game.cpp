class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool flag=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=0) continue;
            flag=false;
            int count=1;
            int j=i-1;
            while(j>=0){
                if(nums[j]>count){
                    flag=true;
                    break;
                }else{
                    count++;
                    j--;
                }
            }
            i=j;
        }
        return flag;
    }
};