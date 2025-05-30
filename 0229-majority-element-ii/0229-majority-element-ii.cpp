class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Moore Voting

        vector<int> ans;

        int count1=0,count2=0,el1=-1,el2=-1;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && el2!=nums[i]){
                count1=1;
                el1=nums[i];
            }
            else if(count2==0 && el1!=nums[i]){
                count2=1;
                el2=nums[i];
            }
            else if (nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        // Manual Check
        count1=0;
        count2=0;
        for(int x: nums){
            if(x==el1) count1++;
            if(x==el2) count2++;
        }

        if(count1>nums.size()/3) ans.push_back(el1);
        if(count2>nums.size()/3 && el1!=el2) ans.push_back(el2);

        return ans;

    }
};