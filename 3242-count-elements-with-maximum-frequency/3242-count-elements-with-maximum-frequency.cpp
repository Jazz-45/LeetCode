class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxFreq=0;
        for(int x: nums){
            m[x]++;
            maxFreq=max(maxFreq,m[x]);
        }

        int sum=0;
        for(auto p: m){
            if(p.second==maxFreq) sum+=p.second;
        }
        return sum;


    }
};