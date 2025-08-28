class Solution {
public:
    vector<int> dp;
    bool isPalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string& s,int i){
        if(i==s.length()) return 0;

        if(dp[i]!=-1) return dp[i];

        int minCost=INT_MAX;
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                int cost=1+helper(s,j+1);
                minCost=min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        dp.clear();
        dp.resize(s.length(),-1);
        return helper(s,0)-1;
    }
};