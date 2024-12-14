class Solution {
public:

    vector<int> dp;

    int ftd(int n){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=ftd(n-1)+ftd(n-2)+ftd(n-3);
    }

    int fbu(int n){
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }

    int tribonacci(int n) {
        // DP Solution

        dp.clear();
        dp.resize(100,-1);
        return fbu(n);
    }
};