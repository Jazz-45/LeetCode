class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int> nextLargest(n,-1);

        int currLargest=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>=currLargest){
                nextLargest[i]=-1;
            }
            else{
                nextLargest[i]=currLargest;
            }
            currLargest=max(currLargest,prices[i]);
        }

        int profit=-1;
        for(int i=0;i<n-1;i++){
            if(nextLargest[i]==-1) continue;
            else profit=max(profit,nextLargest[i]-prices[i]);
        }

        if(profit==-1) return 0;
        return profit;
    }
};