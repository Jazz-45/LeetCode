class Solution {
public:
    bool capacity(vector<int>& weights, int days,int mid){
        
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days--;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        if(days<=0) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;

            if(capacity(weights,days,mid)==true) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};