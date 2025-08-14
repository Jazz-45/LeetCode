class Solution {
public:
    vector<int> dp;
    int helper(int n){
        // Memoization
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=helper(n-1)+helper(n-2);
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(n+1,-1);
        // return helper(n);

        if(n==1) return 1;  // These lines are here because the line dp[2]=2;
        if(n==2) return 2;  // gives error when dp is of size 1 or 2;

        // dp[1]=1;
        // dp[2]=2;
        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        int prev=2;
        int prev2=1;
        int curr=prev+prev2;
        for(int i=3;i<=n;i++){
            curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};