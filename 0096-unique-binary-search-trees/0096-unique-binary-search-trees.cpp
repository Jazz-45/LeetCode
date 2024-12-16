class Solution {
public:
    vector<int> dp;
    
    int ftd(int n){
        if(n==1 || n==0) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];

        int sum=0;
        for(int k=1;k<=n;k++){ // k-> potential node
            sum+=ftd(k-1)*ftd(n-k);
        }
        return dp[n]=sum;
    }

    int fbu(int n){
        dp.clear();
        dp.resize(30,0);
        dp[0]=dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int k=1;k<=i;k++){ // k-> potential node
                dp[i]+=dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(25,-1);
        return fbu(n);
    }
};