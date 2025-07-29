class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();

        priority_queue<long long> pq(target.begin(),target.end());
        long long sum=accumulate(target.begin(),target.end(),0LL);

        long long maxEle,remSum,ele;

        while(pq.top()!=1){
            maxEle=pq.top();
            pq.pop();

            remSum=sum-maxEle;

            // Base Cases
            if(remSum<=0 || remSum>=maxEle) return false;

            // TLE Avoidance
            // ele=maxEle-remSum;
            ele=maxEle%remSum;

            if(ele==0){
                if(remSum==1) return true;
                else return false;
            }
            sum=remSum+ele;
            pq.push(ele);
        }
        return true;
    }
};