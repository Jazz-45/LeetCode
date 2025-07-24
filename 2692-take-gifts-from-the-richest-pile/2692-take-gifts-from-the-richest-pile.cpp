class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pq(gifts.begin(),gifts.end());

        long long sum=0;
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(floor(sqrt(x)));
        }

        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};