class Solution {
public:
    vector<int> dp;
    int f(vector<int>& arr,int i){
        int n=arr.size();
        if(i==n-1) return arr[i]; // single house
        if(i==n-2) return max(arr[i],arr[i+1]); // 2 houses
        return max(arr[i]+f(arr,i+2), 0+f(arr,i+1));
    }
    int ftd(vector<int>& arr,int i){
        int n=arr.size();
        if(i==n-1) return arr[i]; // single house
        if(i==n-2) return max(arr[i],arr[i+1]); // 2 houses
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(arr[i]+ftd(arr,i+2), 0+ftd(arr,i+1));
    }

    int fbu(vector<int>& arr){
        int n=arr.size();
        if(n==1) return arr[0];

        dp.clear();
        dp.resize(n);
        //base case
        dp[n-1]=arr[n-1];
        dp[n-2]=max(arr[n-1],arr[n-2]);
        // ordering;
        for(int i=n-3;i>=0;i--){
            dp[i]=max(arr[i]+dp[i+2],0+dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return fbu(nums);
    }
};