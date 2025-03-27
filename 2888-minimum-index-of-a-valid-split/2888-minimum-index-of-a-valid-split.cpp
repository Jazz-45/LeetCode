class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int x: nums) m[x]++;

        int dominant=nums[0];
        for(auto x: m){
            if(x.second > m[dominant]){  // Compare frequencies correctly
                dominant = x.first;      // Update dominant correctly
            }
        }


        int countd=0;
        for(int i=0;i<=n-2;i++){
            if(nums[i]==dominant) countd++;
            int len1=i+1;
            int len2=n-i-1;

            if((2*countd > len1)&&((m[dominant]-countd)*2>len2)) return i;


        }
        return -1;
    }
};