class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501,0);

        for(int x: arr) freq[x]++;

        for(int i=arr.size();i>=1;i--){
            if(i==freq[i]) return i;
        }

        return -1;
    }
};