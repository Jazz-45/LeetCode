class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n=gifts.size();
        priority_queue<int> pq(gifts.begin(),gifts.end());

        long long left=0;
        while(k--){ // leaving behind gifts;
            int x=pq.top();
            pq.pop(); // largest element
            pq.push(floor(sqrt(x)));
        }

        while(pq.size()>0){
            left+=pq.top();
            pq.pop();
        }
        return left;
    }
};