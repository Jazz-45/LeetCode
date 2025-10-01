class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;

        while(numBottles>=numExchange){
            int filled=numBottles/numExchange;
            int empty=numBottles%numExchange;
            ans+=filled;
            numBottles=empty+filled;
        }
        return ans;
    }
};