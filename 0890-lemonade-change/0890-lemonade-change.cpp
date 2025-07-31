class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        // sort(bills.begin(),bills.end());

        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            if(bills[i]==5){
                m[5]++;
            }
            else if(bills[i]==10){
                if(m.find(5)==m.end()) return false;
                m[10]++;
                m[5]--;
                if(m[5]==0) m.erase(5);
            }
            else{
                if(m.find(5)==m.end()) return false;
                if(m.find(10)!=m.end()){
                    m[10]--;
                    m[5]--;
                    if(m[10]==0) m.erase(10);
                    if(m[5]==0) m.erase(5);
                }
                else{
                    if(m[5]<3) return false;
                    else{
                        m[5]-=3;
                        if(m[5]==0) m.erase(5);
                    }
                }
            }
        }
        return true;
    }
};