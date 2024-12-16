class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<n;i++){
            pair<int,int> p;
            p.first=nums[i];
            p.second=i;
            pq.push(p);
        }

        while(k--){
            pair<int,int> p=pq.top();
            pq.pop();
            p.first*=multiplier;
            pq.push(p);
        }

        while(pq.size()){
            auto p =pq.top();
            nums[p.second]=p.first;
            pq.pop();
        }

        return nums;
    }

    
};