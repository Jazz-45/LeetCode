class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return true;
        if(n==2){
            if((nums[0]%2==0 && nums[1]%2==0)||(nums[0]%2==1 && nums[1]%2==1)) return false;
            else return true;
        }
        for(int i=0;i<n-1;i++){
            if((nums[i]%2==0 && nums[i+1]%2==0)||(nums[i]%2==1 && nums[i+1]%2==1)) return false;
        }
        
    return true;
    }

};