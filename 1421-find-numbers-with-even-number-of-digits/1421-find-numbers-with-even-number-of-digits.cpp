class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int x: nums){
            if(x>=10 && x<=99) count++; 
            if(x>=1000 && x<=9999) count++;
            if(x==100000) count++;
        }
        return count;
    }
};